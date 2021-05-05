#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
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
	int buf,pid;
void handler(void) {
ret = read(fd, buf, 32);
		printf("A kapott szám: %d", buf);
	buf = buf * 2;

	kill(pid, SIGALRM);

	write(fd, buf, sizeof(int));}
int main()
{
    ret = mkfifo("fifo", 0777);



	fd = open("fifo", O_RDWR);
	if (fd == -1) {
	    perror("open() hiba!");
	    exit(-1);
	}

	printf("Add meg a pid-et ");
	scanf("%d", &pid);
	kill(SIGALRM, getpid());
	signal(SIGALRM, (void (*)()) handler);
	pause();
	ret = read(fd, buf, 32);
		printf("A kapott szám: %d", buf);
	buf = buf*2;

	kill(pid, SIGALRM);

	write(fd, buf, sizeof(int));
	close(fd);
	return 0;
}

