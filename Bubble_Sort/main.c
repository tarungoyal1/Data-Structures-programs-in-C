/*
	Bubble sort implementation in C
	Made by Tarun Goyal
	find me on github at https://github.com/tarungoyal1


In bubble sort, we compare each element with its previous element and swap if second is larger than first
till the largest of all is bubbled out at the last. Repeat the process in subarray excluding last index 
each time.

Time Complexity = O(n^2)

*/


#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Bubble_Sort(int * ar, int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
            if(*(ar+j)<*(ar+j-1))
             swap(ar+j, ar+j-1);
        }
    }
}

int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d", &n);

    int * ar = (int *)malloc(n*sizeof(int));

    printf("Enter %d elements in array:",n);

    for(int i=0;i<n;i++)scanf("%d", ar+i);

    Bubble_Sort(ar, n);

    printf("\nSorted array:\n");
    for(int i=0;i<n;i++)
        printf("%d\n", *(ar+i));


    return 0;
}
