#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
main()
{
    char * tira[] = {NULL};
    printf(" proceso que lanza el programa test \n");
    execv("/home/laboratorio/SO/test", tira);
    printf(" proceso que lanzó el programa test \n"); 
}


