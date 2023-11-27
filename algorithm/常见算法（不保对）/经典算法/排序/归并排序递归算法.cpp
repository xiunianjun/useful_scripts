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
	for(int i=0;i<numElements;i++,REnd--){
		a[REnd]=temp[REnd];
		//TODO
	}
}

void MergeSort(int a[],int temp[],int L,int REnd){
	if(L>=REnd){
		return;
		//TODO
	}
	int center=(L+REnd)/2;
	MergeSort(a,temp,L,center);
	MergeSort(a,temp,center+1,REnd);
	Merge(a,temp,L,center+1,REnd);	
} 

int main(){
	int a[8]={8,1,2,5,7,6,3,4};
	int temp[8];
	MergeSort(a,temp,0,7);
	Output(a,8);
} 
