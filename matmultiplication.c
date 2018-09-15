#include<stdio.h>
void matrixprint(int [10][10], int, int);
int a[10][10], b[10][10], r[10][10], i,j,k,r1,c1,r2,c2,sum=0;
int main(){

	printf("Enter row and col size for matrix1:");
	scanf("%d%d", &r1, &c1);

	printf("Enter row and col size for matrix2:");
	scanf("%d%d", &r2, &c2);

	if(c1!=r2){
		printf("Please enter col size of mat1 = row size of mat2\n");
		return 0;
	}
	printf("Enter values of matrix of a:");
	for(i=0;i<r1;i++)
		for(j=0;j<c1;j++)
			scanf("%d", &a[i][j]);

	printf("Enter values of matrix of b:");
	for(i=0;i<r2;i++)
		for(j=0;j<c2;j++)
			scanf("%d", &b[i][j]);

	matrixprint(a, r1, c1);
	matrixprint(b, r2, c2);

	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			for(k=0;k<c1;k++)
				sum = sum + a[i][k]*b[k][j];
			r[i][j] = sum;
			sum=0;
		}
	}

	matrixprint(r, r1, c2);


    return 0;

}

void matrixprint(int m[10][10], int row, int col){
	printf("\n");
	for(i=0;i<row;i++){
		for(j=0;j<col;j++)
			printf("%d\t", m[i][j]);
		printf("\n");
	}
}

