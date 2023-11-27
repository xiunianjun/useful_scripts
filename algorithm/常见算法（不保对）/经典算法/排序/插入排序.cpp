#include <stdio.h>
void charupaixu(int a[],int N){
	for(int i=1;i<N;i++){
		int m=a[i];
		int j=0;
		for(j=i-1;j>=0&&a[j]>m;j--){
			a[j+1]=a[j];
			//TODO
		}
		a[j+1]=m;
		//TODO
	}
}
int main(){
	int a[10]={1,4,3,5,2,6,7,8,10,9};
	charupaixu(a,sizeof(a)/sizeof(int));
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		printf("%d  ",a[i]);
		//TODO
	}
	return 0; 
}
