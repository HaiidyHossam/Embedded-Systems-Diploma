#include <stdio.h>
#include <stdlib.h>

struct Sfirst{
int feet1;
float inch1;
};
struct Ssecond{
int feet2;
float inch2;
};

int main()
{
    struct Sfirst f;
    struct Ssecond s;

    printf("Enter first feet\n");
    scanf("%d",&f.feet1);
    printf("Enter first inch\n");
    scanf("%f",&f.inch1);
    printf("Enter second feet\n");
    scanf("%d",&s.feet2);
    printf("Enter second inch\n");
    scanf("%f",&s.inch2);

int ff=f.feet1+s.feet2;
float i=f.inch1+s.inch2;
if(i>12.0){
    i=i-12;
    ff++;
}
      printf("sum  %d '- %.1f  ",ff,i);
    return 0;
}