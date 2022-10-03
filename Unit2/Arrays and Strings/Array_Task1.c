#include <stdio.h>
#include <stdlib.h>

int main()
{
    float arr1[2][2];
    float arr2[2][2];

     printf("Enter element of first matrix!\n");
    for(int i=0;i<2;i++){

        for(int j=0;j<2;j++){
            printf("enter element:");
            scanf("%f",&arr1[i][j]);
        }
    }
printf("Enter element of second matrix!\n");
     for(int i=0;i<2;i++){

        for(int j=0;j<2;j++){
            printf("enter element:");
            scanf("%f",&arr2[i][j]);
        }
    }
    printf("sum is : \n");
     for(int i=0;i<2;i++){

        for(int j=0;j<2;j++){

            printf("%.1f  ",arr1[i][j] + arr2[i][j]);
            if(j==1){
            printf("\n"); }
        }
        }

    return 0;
}