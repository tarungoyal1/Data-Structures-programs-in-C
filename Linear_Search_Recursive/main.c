/*
    Recursive linear search implementation in C
    Made by Tarun Goyal
    find me on github at https://github.com/tarungoyal1

*/

/*

Time complexity = O(n)

*/

#include <stdio.h>
#include <stdlib.h>

int Linear_Search(int *ar, int *key, int n){
    //we assume the element is to be found at the end of the array

    if(n<0)return -1;
    if(*key==*(ar+n))return n;

    Linear_Search(ar, key, n-1);


}

int main()
{
    int n,*key;
    printf("Enter the size of the array:");
    scanf("%d", &n);

    int *ar = (int *)malloc(n*sizeof(int));

    printf("Enter the %d elements in the array:",n);
    for(int i=0;i<n;i++)
        scanf("%d", ar+i);

    printf("Enter the key element:");
    scanf("%d", key);

    //we passed n-1 because we took array index starting from 0
    int pos = Linear_Search(ar, key, n-1);

    if(pos==-1)printf("Element not found!");

    //keep pos not pos+1 if array index taken from 1
    else printf("Element found at position = %d",pos+1);

    return 0;
}
