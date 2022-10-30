#include <stdio.h>
#include <stdlib.h>

struct SEmployee{
char name [50];
int id;
};

int main()
{
    struct SEmployee e={"Haidy",30};
    struct SEmployee* arr[]={&e};

    printf("Employee name : %s \n",arr[0]->name);

    printf("Employee id : %d",arr[0]->id);

    return 0;
}
