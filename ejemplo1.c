#include <sys/types.h>
#include <stdio.h>
/*programa que ejecuta el mandato ls -1*/
main() {
	pid_t pid;
	int status;
	pid = fork();
	if(pid == 0){ /* proceso hijo*/
		execlp("ls","ls","-1",NULL);
		exit(-1);
	}
	else /* proceso hijo */
		while(pid != wait(&status));
	exit(0);
}