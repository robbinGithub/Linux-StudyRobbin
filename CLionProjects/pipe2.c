#include <stdio.h>
#include <unistd.h>
#define BUF_SIZE 30
 
int main(int argc, char *argv[])
{
    int fds[2];
    char str1[] = "Who are you?";
    char str2[] = "Thank you for your message";
    char buf[BUF_SIZE];
    pid_t pid;
    
    // 创建管道 fds[0]：out | fds[1] in
    pipe(fds);
    pid = fork();
    if (pid == 0)
    {
        // 子进程向管道写数据
        write(fds[1], str1, sizeof(str1));
        //sleep(2);
        // 子进程从管道读取数据
        read(fds[0], buf, BUF_SIZE);
        printf("Child proc output: %s \n", buf);
    }
    else
    {   
        // 主进程从管道读取数据
        read(fds[0], buf, BUF_SIZE);
        printf("Parent proc output: %s \n", buf);
        // 主进程向管理写入数据
        write(fds[1], str2, sizeof(str2));
        sleep(3);
    }
    return 0;
}
