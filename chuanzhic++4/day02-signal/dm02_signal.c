#include <signal.h>

void handler(int num)
{
  printf("recv num:%d\n", num);
  if(num == SIGQUIT)
  {
    exit(0);
  }
}

int main()
{
  char tmpchar;
 // __sighandler_t old = signal(SIGINT, handler);
  if(signal(SIGINT, handler) == SIG_ERR)
  {
    perror("signal err");
    exit(0);
  }
  while((tmpchar =getchar()) != 'a')
  {
    pause();
  }

  signal(SIGINT, SIG_DFL);
  while(1)
  {
  	pause();
  }

}
