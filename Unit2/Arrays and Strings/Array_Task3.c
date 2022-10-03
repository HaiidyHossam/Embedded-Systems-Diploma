#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row,col;
     printf("Enter row and columns of matrix!\n");
     scanf("%d",&row);
     scanf("%d",&col);
    int arr1[row][col];
    int arr2[col][row];
    printf("enter elements of matrix : \n");

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("enter element:");
            scanf("%d",&arr1[i][j]);
        }
    }
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            arr2[j][i]=arr1[i][j];
        }
    }

    printf("enterd matrix: \n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){

            printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }

    printf("Transpose matrix : \n");
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){

            printf("%d ",arr2[i][j]);
        }
        printf("\n");
    }


    return 0;
}
