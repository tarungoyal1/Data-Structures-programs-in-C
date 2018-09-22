/*
	Insertion Sort implementation in C
	Made by Tarun Goyal
	find me on github at http://github.com/tarungoyal1

*/

/*

Time complexity = O(n^2)

*/


#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int * a, int n){
    for(int i=1;i<n;i++){
        int key = *(a+i);
        int j = i;
        while (j>0&&*(a+j-1)>key){
            //swap the values
            int temp = *(a+j);
            *(a+j) = *(a+j-1);
            *(a+j-1) = temp;
            --j;
        }
        *(a+j) = key;
    }
}

int main()
{
    int n;

    printf("Enter the array size:");
    scanf("%d", &n);

    int * ar = (int *) malloc(n*sizeof(int));

    printf("Enter the elements in array:");
    for(int i=0;i<n;i++)
        scanf("%d", ar+i);

    insertion_sort(ar, n);
    printf("\nSorted array:\n");
    for(int i=0;i<n;i++)printf("%d ", *(ar+i));
    return 0;
}
