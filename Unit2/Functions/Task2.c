#include <stdio.h>
#include <stdlib.h>

int Fact(int x);

int main()
{

    int num1;
    int result;
    printf("Enter positive integer\n");
    scanf("%d",&num1);
    result= Fact(num1);
    printf("the factorial is %d",result);
    return 0;
}
int Fact(int x){
 int f=1;

 while(x>0){
 f*=x;
    Fact(--x);
 }
 return f;


    }