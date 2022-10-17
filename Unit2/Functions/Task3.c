#include <stdio.h>
#include <stdlib.h>


void Rev(char x[],int y,int k);
int main()
{
char arr[100];
int i=0;
    printf("Enter a sentence\n");
    gets(arr);
    Rev(arr,0,strlen(arr)-1);
    printf("The reverse is %s",arr);


    return 0;
}
void Rev(char x[],int y,int k){
//massoH ydiaH
    char temp;
    temp = x[y];
    x[y] = x[k - y];
    x[k - y] = temp;
    if (y == k / 2)
    {
        return;
    }
    Rev(x, y + 1, k);


 }