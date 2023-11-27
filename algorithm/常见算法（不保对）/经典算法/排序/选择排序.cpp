#include <stdio.h>
#include <stdlib.h> 

void Output(int a[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
		//TODO
	}
}

void SelectSort(int a[],int n){
	for(int i=n-1;i>=0;i--){
		int maxIndex=i;
		for(int j=0;j<i;j++){
			if(a[j]>a[maxIndex]){
				maxIndex=j;
				//TODO
			}
			//TODO
		}
		int temp=a[maxIndex];
		a[maxIndex]=a[i];
		a[i]=temp;
		//TODO
	}
}

int main(){
	int a[8]={8,1,5,2,7,6,3,4};
	SelectSort(a,8);
	Output(a,8);
} 
