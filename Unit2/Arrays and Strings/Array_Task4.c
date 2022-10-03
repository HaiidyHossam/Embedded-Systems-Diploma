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
     printf("Enter element to be inserted \n");
     int inserted=0;
     scanf("%d",&inserted);
      printf("Enter location\n");
     int loc=0;
     scanf("%d",&loc);
      int arr1[x+1];
        for(int i=0;i<=x;i++){
    arr1[i]=arr[i];
     }
       int p=arr1[loc-1];
        arr1[loc-1]=inserted;

     for(int i=loc;i<=x;i++){

    arr1[i]=p;  p=arr[i];
     }
      for(int i=0;i<=x;i++){
           printf("%d ",arr1[i]);
     }



    return 0;
}
