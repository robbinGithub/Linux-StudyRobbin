//
// Created by Administrator on 2019/11/16 0016.
//
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
//#include <arpa/inet.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

/*
 * Linux平台：一个简单的TCP6 server的示例代码(socket)
 *
 * https://blog.csdn.net/wlqingwei/article/details/43982975
 */
int main_6(int argc, char *argv[]) {

     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in6 serv_addr, cli_addr;
     int n;

     sockfd = socket(AF_INET6, SOCK_STREAM, 0);
     if (sockfd < 0)
     {
         error("ERROR opening socket");
     }
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = 5020;

     serv_addr.sin6_family = AF_INET6;
     serv_addr.sin6_addr = in6addr_any;//INADDR_ANY;
     serv_addr.sin6_port = htons(portno);

     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
     {
        error("ERROR on binding");
     }
     listen(sockfd, 5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     if (newsockfd < 0)
     {
        error("ERROR on accept");
     }

     bzero(buffer, 256);
     n = read(newsockfd, buffer, 255);
     if (n < 0) error("ERROR reading from socket");
     printf("Here is the message: %s\n", buffer);
     n = write(newsockfd, "I got your message", 18);
     if (n < 0) error("ERROR writing to socket");

     close(newsockfd);
     close(sockfd);
}

