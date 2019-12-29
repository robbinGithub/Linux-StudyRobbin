#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>
 
#define BUF_SIZE 100
void error_handling(char *buf);
 
int main(int argc, char *argv[])
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    struct timeval timeout;
    
    // 文件描述符信合
    fd_set reads, cpy_reads;
 
    socklen_t adr_sz;
    int fd_max, str_len, fd_num, i;
    char buf[BUF_SIZE];
    if (argc != 2) {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }
 
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));
 
    if (bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("bind() error");
    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");
    
    // 初始化
    FD_ZERO(&reads);
    // 把监听套节字添加到集合中
    FD_SET(serv_sock, &reads);
    // 找到最大的套接字
    fd_max = serv_sock;
 
    while (1)
    {
        // 结构体拷贝
	cpy_reads = reads;
        timeout.tv_sec = 5;
        timeout.tv_usec = 5000;
      
	// 速度慢原因1：每次调用select函数时,都需要向该函数传递监视对象信息
        if ((fd_num = select(fd_max + 1, &cpy_reads, 0, 0, &timeout)) == -1)
            break;
        if (fd_num == 0)
            continue;
        
        // 速度慢原因2：每次调用select函数后,常见的针对所有文件描述符的循环语句	
        for (i = 0; i < fd_max + 1; i++)
        {
            if (FD_ISSET(i, &cpy_reads))
            {
                if (i == serv_sock) // connection request!
                {
                    adr_sz = sizeof(clnt_adr);
                    clnt_sock =
                        accept(serv_sock, (struct sockaddr *)&clnt_adr, &adr_sz);
                    FD_SET(clnt_sock, &reads);
                    if (fd_max < clnt_sock)
                        fd_max = clnt_sock;
                    printf("connected client: %d \n", clnt_sock);
                }
                else // read message!
                {
                    str_len = read(i, buf, BUF_SIZE);
                    if (str_len == 0) // close request!
                    {
                        // 清除套节字
			FD_CLR(i, &reads);
                        close(i);
                        printf("closed client: %d \n", i);
                    }
                    else
                    {
                        write(i, buf, str_len); // echo!
                    }
                }
            }
        }
    }
    close(serv_sock);
    return 0;
}
 
void error_handling(char *buf)
{
    fputs(buf, stderr);
    fputc('\n', stderr);
    exit(1);
}
