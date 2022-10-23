#include <stdio.h>
#include <stdlib.h>

typedef struct Scompex{
float real;
float img;
}c;

c add(c n1,c n2){
c sum;
sum.real=n1.real+n2.real;
sum.img=n1.img+n2.img;
return sum;


}

int main()
{
    c n1,n2;
    c sum;

    printf("Enter first number\n");
    scanf("%f %f",&n1.real,&n1.img);

    printf("Enter second num\n");
    scanf("%f %f",&n2.real,&n2.img);
sum=add(n1,n2);
printf("sum=%.1f+%.1fi",sum.real,sum.img);

    return 0;
}