/*
    Linear_Search implementation in C
    Made by Tarun Goyal
    find me on github at https://github.com/tarungoyal1

*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,*key, flag=0;


    printf("Enter the size of array:");
    scanf("%d", &n);

    int * ar = (int *)malloc(n*sizeof(int));

    printf("Enter the %d elements in the array:\n", n);

    for(int i=0;i<n;i++)scanf("%d", ar+i);

    printf("\nEnter the element to be searched:");
    scanf("%d", key);

    int i=0;
    for(;i<n;i++){
        if(*(ar+i)==*key){
            flag=1;
            break;
        }
    }

    //for index based position, keep i not i+1
    if(flag)printf("Element found at position = %d", i+1);
    else printf("Element not found!");

    return 0;
}
