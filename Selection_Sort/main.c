/*
    Selection sort implementation in C
    Made by Tarun Goyal
    find me on github at https://github.com/tarungoyal1

In selection sort, we find minimum/maximum element (based on order of sorting) from
unsorted array and put that element at begining/last and repeat the process in sub array excluding the sorted part.
We do this n times and minumim function also runs for n times in worst case, so total complexity will be:

Time Complexity  = O(n^2);

*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int minimum(int * ar, int start, int n){
    int m = start;
    int element = *(ar+m);

    for(int i=start+1;i<n;i++){
        if(element>*(ar+i)){
            element = *(ar+i);
            m = i;
        }
    }
    return m;
}

void Selection_Sort(int * ar, int n){

    for(int i=0;i<n;i++){
        int min = minimum(ar, i, n);
        if(min!=i)swap(ar+i, ar+min);
    }


}

int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d", &n);

    int * ar = (int *)malloc(n*sizeof(int));

    printf("Enter %d elements in the array:", n);

    for(int i=0;i<n;i++)scanf("%d", ar+i);

    Selection_Sort(ar, n);

    printf("\nSorted array:\n");
    for(int i=0;i<n;i++)printf("%d\n", *(ar+i));

    return 0;
}
