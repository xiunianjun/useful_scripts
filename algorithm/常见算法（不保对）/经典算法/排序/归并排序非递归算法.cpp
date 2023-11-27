#include <stdio.h>
#include <stdlib.h> 

void Output(int a[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
		//TODO
	}
	printf("\n");
}

void Merge(int a[],int temp[],int L,int R, int REnd){
	int LEnd=R-1;
	int tmp=L;
	int numElements=REnd-L+1;
	while(L<=LEnd&&R<=REnd){
		if(a[L]>a[R]){
			temp[tmp++]=a[R++];
			//TODO
		}
		else{
			temp[tmp++]=a[L++];
		}
		//TODO
	}
	while(L<=LEnd){
		temp[tmp++]=a[L++];
		//TODO
	}
	while(R<=REnd){
		temp[tmp++]=a[R++];
		//TODO
	}
}

void MergeUnion(int a[],int temp[],int n,int lenth){
	int i;
	for(i=0;i+2*lenth-1<n;i+=2*lenth){
		Merge(a,temp,i,i+lenth,i+2*lenth-1);
		//TODO
	}
	if(i+lenth<n){
		Merge(a,temp,i,i+lenth,n-1);
		//TODO
	}
	else{
		for(;i<n;i++){
			temp[i]=a[i];
			//TODO
		}
	} 
} 

void MergeSort(int a[],int n){
	int lenth=1;
	int* temp=(int*)malloc(sizeof(int)*n); 
	while(lenth<n){
		MergeUnion(a,temp,n,lenth);
		lenth*=2;
		MergeUnion(temp,a,n,lenth);
		lenth*=2;
		//TODO
	}
	free(temp);
}

int main(){
	int a[8]={8,1,2,5,7,6,3,4};
	MergeSort(a,8);
	Output(a,8);
} 
