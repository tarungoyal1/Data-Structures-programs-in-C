#include <stdio.h>
#include <stdlib.h>

//This returns approximate Square root of non-perfect squares
//but is highly effecient as it uses binary Search to find square roots

float SquareRoot(float n){
    if(n<=1)return n;

    float beg=0;
    float end=n;
    float mid=(beg+end)/2;

    int counter=0;
    int prevmid=0;

    while((mid*mid)!=n&&beg<=end){
        if((mid*mid)>n)end = mid;
        else beg=mid;
        mid = (beg+end)/2;

        if ((int)prevmid==(int)mid)counter++;
        if(counter>10)return mid;
        prevmid=mid;

    }
    return mid;
}


int main()
{
    float num;
    printf("Enter the number:");
    scanf("%f", &num);
    float sqroot = SquareRoot(num);
    printf("Square root = %f", sqroot);
    return 0;
}
