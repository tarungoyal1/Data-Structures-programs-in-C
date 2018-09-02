#include <stdio.h>
#include <stdlib.h>

int maxIndex(int a, int b){
    if(a>b)return 1;
    else if(b>a)return 2;
}

int maxNum(int a, int b){
    if(a>b)return a;
    else if(b>a)return b;
}
int main()
{   int i,n,max, temp, heap[10];

    printf("Enter number of elements:");
    scanf("%d", &n);

    //int heap[n];

    printf("Enter elements in the array:");
    for(i=0;i<n;i++)
        scanf("%d", &heap[i]);


    // if parent node is at index i, then it has child nodes at index 2i+1 and 2i+2
    //Building max heap

     for(i=(n/2)-1;i>=0;i--){
        //this is only for last leaf node who has no sibling
        if(2*i+2>=n){
            if(heap[2*i+1]>heap[i]){
                max = maxNum(heap[i], heap[2*i+1]);
                temp = heap[i];
                heap[i] = max;
                heap[2*i+1] = temp;
                continue;
            }
        }

        if(heap[2*i+1]>heap[i]||heap[2*i+2]>heap[i]){

            //find index of maximum element, here max variable has either 1 or 2 as index position of maximum element
            max = maxIndex(heap[2*i+1], heap[2*i+2]);


            //swap the max element

            temp = heap[i];
            heap[i] = heap[2*i+max];
            heap[2*i+max] = temp;
        }
     }

     for(i=0;i<n;i++)
        printf("%d, ", heap[i]);


    return 0;
}
