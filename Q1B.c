//Code to block

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

sigset_t signal_set; 
sigemptyset(&signal_set);

sigaddset(&signal_set, SIGSEGV);
sigaddset(&signal_set, SIGRTMIN);


sigprocmask(SIG_BLOCK, &signal_set, NULL): 

kill(0,SIGSEGV);  
kill(0,SIGSEGV);  
sigprocmask(SIG_UNBLOCK, &signal_set, NULL); 