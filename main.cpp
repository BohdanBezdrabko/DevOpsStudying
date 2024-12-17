#include <iostream>
#include "FuncA.h"
#include <sys/wait.h>
int CreateHTTPserver();
void sigchldHandler(int s)
{
  printf("Caught signal SIGCHLD\n");

  pid_t pid;
  int status;

  while ((pid = waitpid(-1,&status,WNOHANG)) > 0)
  {
    if (WIFEXITED(status)) printf("\nChild process terminated");
  }
}
void sigintHandler(int s)
{
  printf("Caught signal %d. Starting graceful exit procedure\n",s);

  pid_t pid;
  int status;
  while ((pid = waitpid(-1,&status,0)) > 0)
  {
    if (WIFEXITED(status)) printf("\nChild process terminated");
  }
  
  if (pid == -1) printf("\nAll child processes terminated");

  exit(EXIT_SUCCESS);
}
int main() {
    Function obj;
    signal(SIGCHLD, sigchldHandler);
    signal(SIGINT, sigintHandler);


   // std::cout << "FuncA calculation result (x = " << x << ", n = " << n1 << "): " << obj.FuncA(0.1, 5) << std::endl;
   // std::cout << "FuncA calculation result (x = " << x << ", n = " << n2 << "): " << obj.FuncA(0.1, 7) << std::endl;
   CreateHTTPserver();
   return 0;
}
