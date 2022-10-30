#include <stdio.h>
#include <stdlib.h>

int main()
{
     int m;
     m=29;
     printf("address of m:%p \n",&m);
     printf("value of m:%d \n",m);
     int* ab;
     ab=&m;
     printf("address of ab:%p \n",ab);
     printf("content of ab:%d \n",*ab);
     m=34;
     printf("address of ab:%p \n",ab);
     printf("content of ab:%d \n",*ab);
     *ab=7;
     printf("address of m:%p \n",&m);
     printf("value of m:%d \n",m);
    return 0;
}
