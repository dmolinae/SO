#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
main()
{
    printf(" proceso que lanza el programa test \n");
    system("/home/laboratorio/SO/test"); 
    printf(" proceso que lanzó el programa test \n"); 
}


