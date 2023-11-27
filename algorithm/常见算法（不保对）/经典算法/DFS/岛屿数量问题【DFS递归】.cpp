#include <stdio.h>
#define M 4
#define N 5

void PrintArray(int a[M][N]){
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			printf("%d",a[i][j]);
			//TODO
		}
		printf("\n");
		//TODO
	}
}

void BeZero(int a[M][N],int i,int j,int m,int n){
	if(i>=m||j>=n||a[i][j]==0||i<0||j<0){
		return;
		//TODO
	}
	a[i][j]=0;
	BeZero(a,i-1,j,m,n);
	BeZero(a,i+1,j,m,n);
	BeZero(a,i,j-1,m,n);
	BeZero(a,i,j+1,m,n);
}

int FindIsland(int a[M][N],int m,int n){
	int count=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==1){
				count++;
				BeZero(a,i,j,m,n);
				//TODO
			}
			//TODO
		}
		//TODO
	}
	return count;
}

int main(){
	int m=M,n=N;
	int a[m][N];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			//TODO
		}
	}
	int count=FindIsland(a,m,n);
	printf("%d",count);
	return 0; 
}
