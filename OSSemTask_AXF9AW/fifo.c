#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

int fd, ret;
int buf;
void handler(void) {
ret = read(fd, buf, 32);
	printf("A read() olvasott %d byteot: %d\n", ret, buf);}
int main()
{
        ret = mkfifo("fifo", 0777);
	if (ret == -1) {
	    perror("mkfifo() hiba!\n");
	    exit(-1);
	}

	fd = open("fifo", O_RDWR);
	if (fd == -1) {
	    perror("open() hiba!\n");
	    exit(-1);
	}
	int pid;
	printf("Add meg a pid-et ");
	scanf("%d", &pid);
	srand(time(NULL));
	buf = rand()%100;

	write(fd, buf, sizeof(int));
	signal(SIGALRM, (void (*)()) handler);
	pause();


	close(fd);

	unlink("fifo");

    return 0;
}
