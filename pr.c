#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
main()
{
    char * tira[] = {NULL};
    printf(" proceso que lanza el programa test \n");
    execv("/home/rvega/Escritorio/test", tira);
    printf(" proceso que lanzó el programa test \n"); 
}


