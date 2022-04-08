#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    pid_t pid;
    int r;
    char *ch=NULL;
    char *ch1=NULL;
    int readpipe[2];
    int writepipe[2];
    int a;
    int b;
    a=pipe(readpipe);
    b=pipe(writepipe);

    pid=fork();

    if(pid==0)
    {
            close(readpipe[1]);
            close(writepipe[1]);
            read(readpipe[0],ch,sizeof(ch));
            printf("\nREAD = %s",ch);
            close(readpipe[0]);
            ch1="YES";
            write(writepipe[1],ch1,sizeof(ch1));
            close(writepipe[1]);
    }
    else
    { 
            close(writepipe[0]);
            close(writepipe[1]);
            ch="HI!! YOU THERE";
            write(readpipe[1],ch,sizeof(ch));
            close(readpipe[1]);
            read(writepipe[1],ch1,sizeof(ch1));
            printf("\nACK RECEIVED %s",ch1);
            close(writepipe[1]);
    }
    return 0;
}