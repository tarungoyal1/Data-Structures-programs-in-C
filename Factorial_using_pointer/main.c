#include <stdio.h>
#include <stdlib.h>

int main()
{   int *p, n, *f, fact=1;
    printf("Enter number:");
    scanf("%d", p=&n);


    while(*p>=1){
        fact = fact**p;
        --*p;
    }

    f = &fact;
    printf("%d", *f);
    return 0;
}
