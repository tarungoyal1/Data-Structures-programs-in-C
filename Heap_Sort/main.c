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

    int * parent = heap+index;
    int * left = heap+2*index;
    int * right = heap+(2*index+1);

//    printf("%d, %d, %d, %d\n", *parent, *left, *right, *(heap+(index/2)));
//    return;

    //before checking for children check for its parent
    if(index>1){
        if(*(heap+(index/2))<*parent){
            swap(heap+(index/2), parent);
        }
    }

    //now check for children
    if(*parent<*left||*parent<*right){
        swap(maximumNode(left, right), parent);
        restore(heap, index/2);
    }
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
*(heap+1) = 25;
*(heap+2) = 35;
*(heap+3) = 18;
*(heap+4) = 9;
*(heap+5) = 46;
*(heap+6) = 70;
*(heap+7) = 48;
*(heap+8) = 23;
*(heap+9) = 78;
*(heap+10) = 12;
*(heap+11) = 95;
//    printf("Enter %d elements in heap, separated by space or line by line:\n", n);
//    for(int i=1;i<=n;i++)scanf("%d", heap+i);

    max_heapify(heap, n);

    for(int i=1;i<=n;i++)printf("%d:%d\n",i,*(heap+i));



    return 0;
}
