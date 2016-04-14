#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
void main(void){ 
	int fildes1[2],fildes2[2]; /* Se crea un pipe, se utiliza un arreglo de tamaño 2 donde 
					  			arreglo[0] es para leer y arreglo[1] es para escribir */
	char *valores[2],suma;
	pipe(fildes1);
	pipe(fildes2);

	if(fork() == 0){
		strcpy('4',valores[0]);
		strcpy('5',valores[1]);
		/*valores[0] = 4;
		valores[1] = 5;*/
		write(fildes1[1],&valores,2);
		read(fildes2[0],&suma,1);
		printf("La suma es: %i \n",suma);
	}
	else{
		read(fildes1[0],&valores,2);
		suma = valores[0] + valores[1];
		write(fildes2[1],&suma,1);
	}
}