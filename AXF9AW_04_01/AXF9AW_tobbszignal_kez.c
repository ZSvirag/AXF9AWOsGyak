#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void interrupt(int jel);
void exit(int jel);

unsigned int interrupts = 0;

int main(void)
{
    if (signal(SIGINT, interrupt) == SIG_ERR)
    {
        printf("Failed!");
        return 0;
    }

    if (signal(SIGQUIT, exit) == SIG_ERR)
    {
        printf("Failed!");
        return 0;
    }

    while(interrupts < 2)
    {
        printf("Waiting to sign\n");
        sleep(1);
    }

    printf("The second sign arrived");
    return 0;
}

void interrupt(int jel)
{
    printf("SIGINT sign: %d\n", jel);
    interrupts++;
}

void exit(int jel)
{
    printf("SIGQUIT sign: %d\n", jel);
}
