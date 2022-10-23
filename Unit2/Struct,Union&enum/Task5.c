#include <stdio.h>
#include <stdlib.h>
#define PI 3.14
#define aree(r) (PI*(r)*(r))
int main()
{

int rad;
float area;
printf("enter readious \n");
scanf("%d",&rad);
area=aree(rad);
printf("area is %.2f",area);

    return 0;
}
