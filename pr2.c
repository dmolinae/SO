#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main()
{
    char * tira[] = {"test", NULL};
    printf(" proceso que lanza el programa test \n");
    execvp("test", tira);
    printf(" proceso que lanzo el programa test \n"); 
}


