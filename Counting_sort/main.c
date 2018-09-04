/*
    Counting Sort implementation in C
    Made by Tarun Goyal
    find me on github at https://github.com/tarungoyal1

*/

/*

Time Complexity  = O(n+k)
where:
n = total no. of elements in the array
k = max element in array




*/


#include <stdio.h>
#include <stdlib.h>

int findmax(int * ar, int n){
    int max = *ar;
    for(int i=1;i<n;i++){
        if(*(ar+i)>max)max = *(ar+i);
    }
    return max;
}

int main()
{   int n;
    printf("Enter the number of the array:");scanf("%d", &n);

    int * ar = (int *) malloc(n*sizeof(int));

    printf("Enter %d elements in the array:", n);
    for(int i=1;i<=n;i++)
        scanf("%d", ar+i);

    int max = findmax(ar, n);
    printf("\nmax = %d", max);

    int * c = (int*)malloc((max+1)*sizeof(int));

    for(int i=1;i<=max;i++)*(c+i) = 0;

    //fill count array by counting occurrences
    for(int i=1;i<=n;i++)
        *(c + *(ar+i)) = ++(*(c + *(ar+i)));

    // now c[i] contains number of element equal to i
//    for(int i=1;i<=max;i++)printf("%d,", *(c+i));

    for(int i=2;i<=max;i++)
        *(c + i) = *(c+i) + *(c+i-1);

    printf("\n");

    // now c[i] contains number of elements less than or equal to i
//    for(int i=1;i<=max;i++)printf("%d,", *(c+i));

    int * b = (int *) malloc(n*sizeof(int));


    for(int i=n;i>=1;i--){
        *(b+*(c + *(ar+i))) = *(ar+i);
        *(c + *(ar+i)) = --*(c + *(ar+i));
    }
    printf("\nSorted array:\n");
    for(int i=1;i<=n;i++)printf("%d ", *(b+i));


    return 0;
}
