/*
    Quick_Sort in C (2016)
    Tarun Goyal
    find me on github at: https://github.com/tarungoyal1

Algo:

QuickSort(A, start, end){
    if start<end
        do q = Partition
        QuickSort(A, start, q-1)
        QuickSort(A, q+1, end)
}

Partition(A, start, end){

    x <-- A[end] //Pivot element
    i <-- start -1 //counter

    for j <-- start to end-1
        if A[j] <= x
            do ++i
            swap A[i] <--> A[j]
    // end of for loop
    swap A[i+1] <--> x
    return i+1
}
*/

#include <stdio.h>
#include <stdlib.h>

int *ar,n;

//swap function is not needed if you're using non-pointer version of array
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void quicksort(int start, int end){

    if(start<end){
        int q = partition(start, end);
        quicksort(start, q-1);
        quicksort(q+1, end);
    }
}

int partition(int start, int end){
    int x = *(ar+end); //we're taking last element as pivot element
    int i = start-1;

    for (int j=start;j<end;j++){
        if(*(ar+j)<x){
            ++i;
            swap(ar+i, ar+j);
        }
    }
    ++i;
    swap(ar+i, ar+end); //remember don't swap with x, it's just a local var
    return i; //this will be returned to q
}

int main()
{
    printf("Enter array size:");
    scanf("%d", &n);
    ar = (int *)malloc(n*sizeof(int));
    printf("Enter %d elements in the array:",n);
    for(int i=1;i<=n;i++)scanf("%d", ar+i);

    quicksort(1,n);
    printf("\nSorted array:\n");
    for(int i=1;i<=n;i++)printf(" %d,", *(ar+i));

    return 0;
}
