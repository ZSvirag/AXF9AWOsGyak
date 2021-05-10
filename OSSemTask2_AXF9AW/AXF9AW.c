#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
     int pipefd[2];
     pid_t childpid;	
     char buffer;		
     char szovegTombje[32];	
     int ret;

     if (pipe(pipefd) == -1) {	
	   perror("pipe");
	   exit(-1);
     }

     printf("%d: egyik vege: %d, masik vege:%d\n",getpid(),pipefd[0],pipefd[1]);

     childpid = fork();
     if (childpid == -1) {
	   perror("fork");
	   exit(-1);
     }

     if (childpid == 0) {   
	   printf("%d: gyerek vagyok\n",getpid());
	   close(pipefd[1]);    

	   printf("%d: Jelenleg ez van a csoben\n%d: ",getpid(),getpid());
	   while (read(pipefd[0], &buffer, 1) > 0) {	
		 printf("%c",buffer);
	   }
	   printf("\n%d:Lezarom a cso masik veget\n",getpid());

	   close(pipefd[0]);	

   	   exit(0);	

     } else {	
	   printf("%d: szulo vagyok\n",getpid());

   	   close(pipefd[0]);    

	   strcpy(szovegTombje,"Zsidai Virag Roxana AXF9AW\0");  
	   printf("%d: elkuldom ezt a szoveget: %s %d\n",getpid(),szovegTombje,strlen(szovegTombje));

	   write(pipefd[1], szovegTombje, strlen(szovegTombje));

	   close(pipefd[1]);    

	   wait(NULL);  

	   exit(0);
     }
}
