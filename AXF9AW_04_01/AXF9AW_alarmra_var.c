#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
void nothing();

int main(){

    unsigned sec = 5;
    signal(SIGALRM, nothing);
    alarm(sec);
    printf("%d waiting...\n",1);
    pause();
    printf("Alarm has arrived\n");

 return 0;
}

void nothing(){
;
}
