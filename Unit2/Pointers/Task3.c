#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[27];
      char arr2[27];
    printf("input string : \n");
    scanf("%s",&arr);
    int a=strlen(arr);
    int j=0;
    char* p=&arr2;
    for(int i=a-1;i>=0,j<a;i--,j++){
      arr2[j]=arr[i];
    }

    for(int i=0;i<a;i++){
        printf("%c",*p);
        p++;

    }


    return 0;
}
