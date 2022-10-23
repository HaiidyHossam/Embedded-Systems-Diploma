#include <stdio.h>
#include <stdlib.h>

struct SStudent{
char name[50];
int roll;
float marks;
};
int main()
{
    struct SStudent s;

    printf("Enter name\n");
    scanf("%s",&s.name);
      printf("Enter roll number\n");
      scanf("%d",&s.roll);
      printf("Enter marks\n");
      scanf("%f",&s.marks);

      printf("name: %s \n Roll: %d \n mark: %.2f ",s.name,s.roll,s.marks);
    return 0;
}
