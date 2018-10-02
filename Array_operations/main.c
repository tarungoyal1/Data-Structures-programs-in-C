/*
    Basic array operations in C using pointers
    Implemented by Tarun Goyal (Jan, 2016)
    find me on github at https://github.com/tarungoyal1

    Array operations such as:
    Traversal, Insertion, Deletion, Reverse

    Note: we're using 0 based indexing in all our operations
*/

#include <stdio.h>
#include <stdlib.h>

int n;

void traverse(int *ar){
    //simply print the array to demonstrate traversal
    if(n==0){
        printf("Empty array!\n");
        return;
    }
    printf("Final array: %d", *(ar+0));
    for(int i=1;i<n;i++)
    printf(", %d",*(ar+i));
}
void insertion(int *ar,int pos,int val){
    for(int j=n-1;j>=pos;j--)
        *(ar+j+1)=*(ar+j);
    *(ar+pos)=val;
    n++;
}

void deletion(int *ar,int pos){
    if(n==0||pos>=n){
        printf("Invalid position\n");
        return;
    }
    for(int j=pos;j<n;j++)
        ar[j]=ar[j+1];
    n--;
}

void reverse(int * ar){
    //this actually reverses the array not just prints in reverse order
    int s = n-1;

    for(int j=0;j<=s/2;j++)
        //swap the elements at ith position and s-jth position
        swap(ar+j, ar+s-j);

}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int op, pos, val;
    printf("Enter size of the array:");
    scanf("%d", &n);

    int *ar = (int *)malloc(n*sizeof(int));

    printf("\nNow enter %d elements for array:", n);
    for(int i=0;i<n;i++)
        scanf("%d",ar+i);

    traverse(ar);


    printf("\n\n---Now enter operation you want, enter -1 to exit the loop---");

    while(1){

        printf("\n1 to insert an element\n2 to delete an element\n3 to print array elements\n4 to reverse the array:\n");
        scanf("%d",&op);

        if(op<0)break;


        switch(op){
            case 1:
                printf("You chose to insert, for that enter position and value:\n");
                scanf("%d%d",&pos, &val);
                insertion(ar,pos,val);
                traverse(ar);
            break;
            case 2:
                printf("You chose to delete, for that enter position:\n");
                scanf("%d",&pos);
                deletion(ar,pos);
                traverse(ar);
            break;
            case 3:
                printf("You chose to traverse, here is your array:\n");
                traverse(ar);
            break;
            case 4:
                printf("You chose to reverse, here is your array after reversing:\n");
                reverse(ar);
                traverse(ar);
            break;
            default:
                printf("Something went wrong! try again-****--");
            break;
        }
    }

    return 0;
}
