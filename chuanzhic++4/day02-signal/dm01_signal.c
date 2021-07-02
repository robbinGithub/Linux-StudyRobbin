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
  signal(SIGINT, handler);
  signal(SIGQUIT, handler);
  while(1)
  {
    pause();
  }

}
