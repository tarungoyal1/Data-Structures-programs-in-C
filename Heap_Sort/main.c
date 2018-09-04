/* Heap_Sort program implemented in C using pointers
   Also contain the Max_Heapify function that is used in doing Heap_Sort
   Made by Tarun Goyal,
   find me on github at https://github.com/tarungoyal1
 */

/*
Time complexity:
Max_heapify = O(Logn)
Heap_Sort = O(nLogn)
*/

#include<stdio.h>
#include<stdlib.h>

//Index must start from 1 otherwise heap parent-child property will messup

int *maximumNode(int *a, int *b){
    if(*a>*b)return a;
    return b;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int * heap, int current, int n){

    int largest = current;
    int left = 2*current;
    int right = 2*current+1;

    //if left child is greater than parent that is current
    if(left<=n&&*(heap+left)>*(heap+largest))
        largest = left;

    //if right child is greater than parent that is current
    if(right<=n&&*(heap+right)>*(heap+largest))
        largest = right;

    //if parent is not the largest means any of the children is greater
    if(largest!=current){
        swap(heap+current, heap+largest);
        max_heapify(heap, largest, n);
    }
}

void build_max_heap(int * heap, int n){
    for(int i=n/2;i>0;i--)
        max_heapify(heap,i, n);
}

void heap_sort(int * heap, int n){

    build_max_heap(heap, n);

    printf("\nMax Heap:\n");

    for(int i=1;i<=n;i++)printf("%d, ",*(heap+i));

    for(int i=n;i>1;){
        swap(heap+i, heap+1);
        max_heapify(heap, 1, --i);
    }

}

int main(){
    int n;
    printf("Enter the number elements for heap:");
    scanf("%d", &n);
    int * heap = (int *)malloc(n*sizeof(int));
    printf("Enter %d elements in heap, separated by space or line by line:\n", n);
    for(int i=1;i<=n;i++)scanf("%d", heap+i);

    heap_sort(heap, n);

    printf("\n\nSorted array:\n");
    for(int i=1;i<=n;i++)printf("%d, ",*(heap+i));
    printf("\n");

    return 0;
}
