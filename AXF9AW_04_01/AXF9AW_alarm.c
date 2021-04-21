#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void nothing();
void do_int();
int main(){

    int i;
    unsigned sec = 1;

    signal(SIGINT, intComing);

    for(i = 1; i < 11; i++){
        alarm(sec);


        signal(SIGALRM, semmi);
        printf("%d\n", i);
        pause();
    }
  return 0;
}
void intComing(){
        printf("Int has arrived.");
        signal(SIGINT, SIG_IGN);
}

void nothing(){

}
