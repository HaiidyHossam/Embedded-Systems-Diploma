#include <stdio.h>
#include <stdlib.h>

int main()
{
  char x[100];

  int counter =0;
  printf("enter string \n");
 gets(x);


  for(int i=0;x[i]!='\0';i++){



        ++counter;

  }
  printf("the length is %d",counter);

    return 0;
}
