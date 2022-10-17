#include <stdio.h>
#include <stdlib.h>


int Power(int num,int time);
int main()
{
int a,b;
  printf("Enter number\n");
  scanf("%d",&a);
  printf("Enter power ");
  scanf("%d",&b);
 int res= Power(a,b);
printf("power is %d\n",res);
    return 0;
}
int Power(int num,int time){


    int x=1;
   while(time>0){
    x*=num;
    time--; //2 //1
    Power(num, time); }
    return x;

 }
