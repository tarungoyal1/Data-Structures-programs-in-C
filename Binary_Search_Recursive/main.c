#include <stdio.h>
#include <stdlib.h>

int binary_search(int * ar, int beg, int end, int key){
    if(end<beg)return -1;
    int mid=(beg+end)/2;
    if(*(ar+mid)==key)return mid;
    if(key>*(ar+mid))return binary_search(ar, mid+1, end, key);
    else return binary_search(ar, beg, mid-1, key);

}

int main()
{
    int n, element;
    printf("Enter the size of the array:");
    scanf("%d", &n);

    int * ar = (int *)malloc(n*sizeof(int));

    printf("Enter %d elements in the array:", n);
    for(int i=0;i<n;i++)scanf("%d", ar+i);

    printf("Enter the element to search:");
    scanf("%d", &element);


    int pos = binary_search(ar, 0, n-1, element);
    printf("%d", pos);


    return 0;
}
