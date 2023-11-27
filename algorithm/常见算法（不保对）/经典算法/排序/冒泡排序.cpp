#include <stdio.h>
void Bubble_Sort(int a[],int N){
	for(int i=N-1;i>=0;i--){ 
		for(int j=1;j<=i;j++){
			if(a[j-1]<a[j]){//若是此处取等，排序会不稳定哦 
				int t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
				//TODO
			}
			//TODO
		}
		//TODO
	}
}
int main(){
	int a[5]={5,3,2,4,1};
	Bubble_Sort(a,sizeof(a)/sizeof(int));
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		printf("%d  ",a[i]);
		//TODO
	}
	return 0; 
}
