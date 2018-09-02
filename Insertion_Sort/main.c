#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int * a, int n){
    for(int j=1;j<n;j++){
        int key = *(a+j);
        int i = j-1;
        while (i>-1&&*(a+i)>key){
            //swap the values
            int temp = *(a+i+1);
            *(a+i+1) = *(a+i);
            *(a+i) = temp;
            --i;
        }
        *(a+i+1) = key;
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

    for(int i=0;i<n;i++)printf("%d\n", *(ar+i));
    return 0;
}
