#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter number of elements\n");
    int x=0;
    scanf("%d",&x);
    float arr1[x];
    float sum=0;
    float avg;


    for(int i=0;i<x;i++){

            printf("enter number:");
            scanf("%f",&arr1[i]);
            sum+=arr1[i];
        }
    avg=sum/x;

            printf("avg is %.2f :",avg);


    return 0;
}