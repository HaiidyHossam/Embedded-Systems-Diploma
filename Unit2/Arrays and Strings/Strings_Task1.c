#include <stdio.h>
#include <stdlib.h>

int main()
{
  char x[100];
  char y;
  int counter =0;
  printf("enter string \n");
 gets(x);
    printf("enter character  \n");
    scanf("%c",&y);

  for(int i=0;x[i]!='\0';i++){

    if(x[i]==y){

        ++counter;
    }
  }
  printf("the frequency is %d",counter);

    return 0;
}
