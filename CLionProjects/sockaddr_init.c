#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
int main(int argc, char *argv[])
{
    struct sockaddr_in addr;
    char *serv_ip = "211.217.168.13";          //声明IP地址字符串
    char *serv_port = "8500";                  //声明端口号字符串
    memset(&addr, 0, sizeof(addr));            //结构体变量addr的所有成员初始化为0
    addr.sin_family = AF_INET;                 //指定地址族
    addr.sin_addr.s_addr = inet_addr(serv_ip); //基于字符串的IP地址初始化
    addr.sin_port = htons(atoi(serv_port));    //基于字符串的端口号初始化
}
