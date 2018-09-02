#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n, ar[10],beg,mid,end,key;
    printf("Enter size of the array:");
    scanf("%d", &n);
    printf("Enter elements of the array:");
    for(i=0;i<n;i++)scanf("%d", &ar[i]);
    for(i=0;i<n;i++)printf("\n%d", ar[i]);

    //binary search
    printf("\nEnter key element to be searched:");
    scanf("%d", &key);

    // remember beg, end, mid are indexes not any element in array
    beg=0;end=n-1;mid=(beg+end)/2;
    while(beg<=end&&ar[mid]!=key){
        if(key<ar[mid])end=mid-1;
        else beg=mid+1;
        mid = (beg+end)/2;
    }
    if(ar[mid]==key) printf("Element found at index position = %d", mid);
    else printf("Element not found, try again with different value.");
    return 0;
}
