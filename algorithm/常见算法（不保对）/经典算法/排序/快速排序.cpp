#include <stdio.h>
#include <stdlib.h> 

void Output(int a[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
		//TODO
	}
	printf("\n");
}

void Swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int FindCenterInThree(int a[],int left,int right){
	int center=(left+right)/2;
	if(a[left]>a[right]){
		Swap(&a[left],&a[right]);
	}
	if(a[left]>a[center]){
		Swap(&a[left],&a[center]);
	}
	if(a[center]>a[right]){
		Swap(&a[center],&a[right]);
	}
	Swap(&a[center],&a[right-1]);
	return a[right-1];
}

void  QuickSort(int a[],int left,int right){
	if(right-left<=1){
		if(a[right]<a[left]){
			Swap(&a[right],&a[left]);
		}
		return;
	}
	int pivot=FindCenterInThree(a,left,right);
	int i=left,j=right-1;
	while(1){
		while(a[++i]<pivot);
		while(a[--j]>pivot);
		if(i<j)
			Swap(&a[i],&a[j]);
		else
			break;
	}
	Swap(&a[i],&a[right-1]);
	QuickSort(a,left,i-1);
	QuickSort(a,i+1,right);
}

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	QuickSort(a,0,n-1);
	Output(a,n);
} 
