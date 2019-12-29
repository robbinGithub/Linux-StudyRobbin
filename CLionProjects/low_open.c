#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
void error_handling(char *message);
int main(void)
{
    int fd;
    char buf[] = "Let's go!\n";
    fd = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC); //<1>
    if (fd == -1)
        error_handling("open() error");
    printf("file descriptor:%d\n", fd);
    
    //向文件写入buf中的数据  
    if (write(fd, buf, sizeof(buf)) == -1) //<2>
        error_handling("write() error!");
    close(fd);
    return 0;
}
void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
