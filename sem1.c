#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sched.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 500
#define NUM_PROCESOS 10

char buffer[BUFFER_SIZE];

int main (int argc, char *argv[ ])
{
char *c;
int i, n= NUM_PROCESOS;
pid_t hijo;
sem_t *semaforo;

if((semaforo=sem_open("/semaforo",O_CREAT,0644, 1))==(sem_t *)-1)
{ perror("No se puede crear el semáforo"); exit(1); }

for (i = 1; i<n; ++i)
{ hijo = fork();
if (hijo ==-1){ perror("No se puede crear el proceso");exit(-1);}	
else if(hijo==0) break; // si es un hijo terminar el for (solo el padre crea los hijos)
}
/* i actua como identificador del proceso en el padre i==n */
sprintf( buffer, "i:%d proceso ID:%d padre ID:%d\n",i, getpid(), getppid());

c = buffer;
/********* Seccion de entrada ****/
if (sem_wait(semaforo) == -1)
{
perror("Semaforo no valido");
exit(1);    }
/**** Principio de la seccion cri�tica *******/

while (*c != '\0')
{
fputc(*c, stderr); fflush(stderr);
c++;
sched_yield(); /* libera la CPU */
}
/********** Fin de la seccion crítica *******/
/*********** Seccion de salida ************/
if (sem_post(semaforo) == -1)
{
perror("Semaforo no valido");
exit(1);
}

/********* Seccion Restante ************/
    sem_close(&semaforo);

/* El Padre espera que termine los n hijos */

 if(i==n)
 	{ printf("Soy el Padre [PID:%d] y voy a esperar a los hijos\n", getpid());
          for(i=1;i<n;i++) wait(0);
        /*  sem_unlink("/semaforo");*/
        }
exit(0);
}

