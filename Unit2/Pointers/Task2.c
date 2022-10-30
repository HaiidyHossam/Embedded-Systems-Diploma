#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[27];
    //"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    char* p=arr;

    for(int i=0;i<26;i++){
      *p=i+'A';
      printf("%c ",*p);
       p++;
    }


    return 0;
}
