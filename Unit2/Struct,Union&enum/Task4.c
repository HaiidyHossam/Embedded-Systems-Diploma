#include <stdio.h>
#include <stdlib.h>

struct SStudent{
int roll;
char name[50];
int marks;
};

int main()
{
    struct SStudent s[10];
    for(int i=0;i<10;i++){
      s[i].roll=i+1;
      printf("enter name \n");
      scanf("%s",&s[i].name);
      printf("enter marks \n");
      scanf("%d",&s[i].marks);

    }
    printf("______________ \n");

     for(int i=0;i<10;i++){
      s[i].roll=i+1;
      printf(" name is %s \n",s[i].name);
      printf(" marks is %d\n",s[i].marks);


    }

    return 0;
}