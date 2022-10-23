#include <stdio.h>
#include <stdlib.h>
struct sstudent{
int x; //4

float y; //4

float z; //4

double r;//12
double e; //12
int gg; //4 */

};

union teacher{
char name[32];
int x;
};
int main()
{
struct sstudent s;
union teacher t;
printf("size of union %d\n",sizeof(union teacher));
printf("size of struct %d\n",sizeof(struct sstudent));


    return 0;
}