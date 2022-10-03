#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=0;
    printf("Enter num of elements \n");
    scanf("%d",&x);
    int arr[x];
    printf("Enter elements \n");
    for(int i=0;i<x;i++){
        scanf("%d",&arr[i]);
    }
     printf("Enter element to be searched\n");
     int search=0;
     scanf("%d",&search);

     for(int i=0;i<x;i++){

    if(arr[i]==search){
         printf("number found at location %d",i+1);
    }
     }


    return 0;
}
