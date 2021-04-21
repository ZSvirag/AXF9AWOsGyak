#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char **argv){

    int pid;

    if(argc < 1){

        perror("Error!");
        exit(1);
    }

    pid = atoi(argv[1]);

    kill(pid, SIGALRM);

return 0;

}
