#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter number of elements: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements: \n");
    int* p=arr;
    for(int i=1;i<=n;i++){
      scanf("%d",&arr[i]);
    }

    for(int i=n;i>=1;i--){
       *p=arr[i];
       printf("%d ",*p);
       p--;

    }

    return 0;
}
