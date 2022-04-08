#include <stdio.h>
#include <signal.h>
 
void sighandler(int sig_num)
{

    signal(SIGTSTP, sighandler);
    printf("Cannot execute Ctrl+Z\n");
}
  
int main()
{ 
    signal(SIGTSTP, sighandler);
    while(1)
    {
    }
    return 0;
}