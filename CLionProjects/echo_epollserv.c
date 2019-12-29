#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
 
#define BUF_SIZE 100
#define EPOLL_SIZE 50
void error_handling(char *buf);
 
int main(int argc, char *argv[])
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t adr_sz;
    int str_len, i;
    char buf[BUF_SIZE];
 
    struct epoll_event *ep_events;
    struct epoll_event event;
    int epfd, event_cnt;
 
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
 
    epfd = epoll_create(EPOLL_SIZE);
    ep_events = malloc(sizeof(struct epoll_event) * EPOLL_SIZE);
 
    event.events = EPOLLIN;
    event.data.fd = serv_sock;
    epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event);
 
    while (1)
    {   
        // 阻塞函数
        event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);
        if (event_cnt == -1)
        {
            puts("epoll_wait() error");
            break;
        }
      
        // 循环IO事件, 如果500客户端同时发数据过来, 循环处理，会引起其他客户端等待, 把IO和业务处理分开，业务用线程池，IO采用多个IO线程
        for (i = 0; i < event_cnt; i++)
        {
            // 有连接进来
            if (ep_events[i].data.fd == serv_sock)
            {  
                // accept连接
                adr_sz = sizeof(clnt_adr);
                clnt_sock =
                    accept(serv_sock, (struct sockaddr *)&clnt_adr, &adr_sz);
                
                // 添加可读取事件至epool
                event.events = EPOLLIN;
                event.data.fd = clnt_sock;
                epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sock, &event);
                printf("connected client: %d \n", clnt_sock);
            }
            else
            {
                // 从套节字读取数据放入应用缓冲区
                str_len = read(ep_events[i].data.fd, buf, BUF_SIZE);
                // 检查读取状态
                // 客户端关闭了
                if (str_len == 0) // close request!
                {
                    epoll_ctl(
                        epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
                    close(ep_events[i].data.fd);
                    printf("closed client: %d \n", ep_events[i].data.fd);
                }
                // 将缓冲区中的数据写入套节字
                else
                {
                    write(ep_events[i].data.fd, buf, str_len); // echo!
                }
            }
        }
    }
    close(serv_sock);
    close(epfd);
    return 0;
}
 
void error_handling(char *buf)
{
    fputs(buf, stderr);
    fputc('\n', stderr);
    exit(1);
}
