/*
    Merge sort in C
    Tarun Goyal
    find me on github at : https://github.com/tarungoyal1

Algo:

Mergesort(A, start, end){
    if (start<end){
       mid <-- floor of (start+end/2)

       Mergesort(A, start, mid)
       Mergesort(A, mid+1, end)
       Merge(A, start, mid, end)
    }
}

Merge(A, start, mid, end){
    n1 <-- mid-start+1
    n2 <-- end - mid

    Create 2 arrays: Left(1...n1+1) and Right(1...n2+1)

    for i <-- 1 to n1
        do Left[i] <-- A[start+i-1]

    for j <-- 1 to n2
        do Right[j] <-- A[mid + j]

    Left(n1+1) <-- Infinity
    Right(n2+1) <-- Infinity

    i <-- 1
    j <-- 1

    for k <-- start to end
        if Left[i] <= Right[j]
            do A[k] <-- Left[i]
            do i++
        else
            do A[k] <-- Right[i]
            do j++
}


Time complexity = O(nLogn)
*/

#include<stdio.h>
#include<stdlib.h>
int *ar,n,i;
void mergesort(int,int);
void merge(int,int,int);
int main(){
 printf("Enter size:");scanf("%d",&n);
 ar = (int *)malloc(n*sizeof(int));
 printf("Enter elements:");
 for(i=1;i<=n;i++)scanf("%d",ar+i);
 mergesort(1,n);
 printf("Sorted array:\n");
 for(i=1;i<=n;i++)printf("%d\n",*(ar+i));
 return 0;
}
void mergesort(int start, int end){
 if(start<end){
  int mid=(start+end)/2;
  mergesort(start,mid);
  mergesort(mid+1,end);
  merge(start,mid,end);
 }
}
void merge(int start, int mid, int end){
 int n1=mid-start+1;
 int n2=end-mid;
 int *la = (int *)malloc(n1*sizeof(int));
 int *ra = (int *)malloc(n2*sizeof(int));
 int i,k,j;

 for(i=1;i<=n1;i++)*(la+i)=*(ar+start+i-1);
 for(j=1;j<=n2;j++)*(ra+j)=*(ar+mid+j);
 *(la+n1+1)=999;
 *(ra+n2+1)=999;
 i=1;j=1;
 for(k=start;k<=end;k++){
  if(*(la+i)<=*(ra+j)){
   *(ar+k)=*(la+i);
   i++;
  }else{
   *(ar+k)=*(ra+j);
   j++;
  }
 }
}
