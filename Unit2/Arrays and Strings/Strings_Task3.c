#include <stdio.h>
#include <stdlib.h>

int main()
{
  char x[100];
char y[100];

  printf("enter string \n");
 gets(x);

int B=strlen(x);
  for(int i=0;i<strlen(x);i++){
y[i] =x[B-1];
  B--;

  }

  printf("the reverse is %s",y);




    return 0;
}
