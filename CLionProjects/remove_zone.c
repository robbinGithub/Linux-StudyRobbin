//
// Created by user on 2019/11/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void read_childproc(int sig)
{
    printf("Receive siangl: %d \n", sig);
    int status;
    pid_t id = waitpid(-1, &status, WNOHANG);
    if(WIFEXITED(status))
    {
        printf("Removed proc id: %d \n", id);
        printf("Child Send: %d \n", WEXITSTATUS(status));
    }
}

int main_remove_zone(int argc, char *argv[])
{
    pid_t pid;
    struct sigaction act;
    act.sa_handler = read_childproc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGCHLD, &act, 0);
    
     pid = fork();
     if(pid == 0)
     {
         puts("HI! I'm child process 1");
         sleep(10);
         printf("walk up after sleep 10s %d \n", getpid());
         return 12;
     } else 
     {
         printf("Child Proc id: %d \n", pid);
         pid = fork();
         if(pid == 0)
         {
             puts("HI! I'm child process 2");
             sleep(10);
             printf("walk up after sleep 10s %d \n", getpid());
             return 24;
         } else 
         {
             int i;
             printf("Child proc id: %d \n", pid);
             for(i = 0;i <10;i++)
             {
                 puts("wait...");
                 sleep(5);
             }
         }
     }
    
     return 0;
}
