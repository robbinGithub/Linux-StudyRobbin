#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(void)
{
	int fd, len;
	int *p;
	fd = open("hello", O_RDWR);
	if(fd<0)
	{ 
		perror("open error"); 
		exit(1);
	}

	len = lseek(fd, 0, SEEK_END);
	p =(int*) mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
        if(p == MAP_FAILED)
	{
            perror("mmap");
            exit(1);
	}
        p[0] = 0x30313233;
        munmap(p, len);
	
}

