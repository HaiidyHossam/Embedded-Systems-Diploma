#include <stdio.h>
#include <stdlib.h>

void Prime(int x,int y);

int main()
{

    int num1,num2;
    printf("Enter two numbers !\n");
    scanf("%d",&num1);
     scanf("%d",&num2);
     Prime(num1,num2);
    return 0;
}
void Prime(int x,int y){
 int flag;
    for(int i=x;i<y;i++){
            flag=0;
            for(int j=2;j<=i/2;j++){
                if(i%j==0){
                   flag=1;
                   break;
                }
            }
                if(flag==0){
                    printf("%d ",i);

                }


    }}

