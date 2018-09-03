#include<stdio.h>
#include<stdlib.h>

//Index must start from 1 otherwise heap parent property will messup



int *maximumNode(int *a, int *b){
    if(*a>*b)return a;
    return b;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void restore(int * heap, int index){
    if(index<1)return;

    int * current = heap+index;
    int * parent = heap+index/2;
    int * left = heap+2*index;
    int * right = heap+(2*index+1);

//    printf("%d, %d, %d, %d\n", *parent, *left, *right, *(heap+(index/2)));
//    return;

    if(index>1){
        int * m1 = maximumNode(left, right);
        if(*m1>*current && *m1>*parent)
            swap(m1, parent);
        if(*current>*parent)
            swap(current, parent);
    }
    int * m2 = maximumNode(left, right);
    if(*m2>*current)
        swap(m2, current);
    restore(heap, index/2);
}

void max_heapify(int * heap, int n){
    for(int i=1;i<=n;i++)printf("%d\t",*(heap+i));
    printf("\n-------------------------------------------------------------------------\n");
    for(int i=n/2;i>0;i--)
        restore(heap,i);
}

int main(){
    int n;
    printf("Enter the number elements for heap:");
    scanf("%d", &n);
    int * heap = (int *)malloc(n*sizeof(int));
    printf("Enter %d elements in heap, separated by space or line by line:\n", n);
    for(int i=1;i<=n;i++)scanf("%d", heap+i);

    max_heapify(heap, n);

    for(int i=1;i<=n;i++)printf("%d:%d\n",i,*(heap+i));



    return 0;
}
