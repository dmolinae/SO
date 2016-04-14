#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*programa que ejecuta el mandato ls -1*/
main() {
	pid_t pid[2];
	int status;
	int i;
	for(i = 0;i < 2;i++){
		pid[i] = fork();
		if(pid[i] == 0) break; /* Si es hijo se sale del for */
	}
	
	if(pid[i] == 0){ /* proceso hijo*/
		execlp("ls","ls","-1",NULL); /* Modifica el texto del proceso */
		exit(-1);
	}
	else /* proceso padre */
		while(pid[i] != wait(&status));
	exit(0);
}