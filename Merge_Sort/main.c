#include<stdio.h>
#include<stdlib.h>
int ar[20],n,i;
void mergesort(int,int);
void merge(int,int,int);
int main(){
 printf("Enter size:");scanf("%d",&n);
 ar[n];
 printf("Enter elements:");
 for(i=1;i<=n;i++)scanf("%d",&ar[i]);
 mergesort(1,n);
 printf("Sorted array:\n");
 for(i=1;i<=n;i++)printf("%d\n",ar[i]);
 return 0;
}
void mergesort(int p, int r){
 if(p<r){
  int q=(p+r)/2;
  mergesort(p,q);
  mergesort(q+1,r);
  merge(p,q,r);
 }
}
void merge(int p, int q, int r){
 int n1=q-p+1;
 int n2=r-q;
 int la[99],ra[99],i,k,j;
 for(i=1;i<=n1;i++)la[i]=ar[p+i-1];
 for(j=1;j<=n2;j++)ra[j]=ar[q+j];
 la[n1+1]=999;
 ra[n2+1]=999;
 i=1;j=1;
 for(k=p;k<=r;k++){
  if(la[i]<=ra[j]){
   ar[k]=la[i];
   i++;
  }else{
   ar[k]=ra[j];
   j++;
  }
 }
}
