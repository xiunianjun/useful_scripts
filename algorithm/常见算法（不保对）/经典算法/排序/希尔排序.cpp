#include <stdio.h>
void printarr(int a[],int N){
	for(int i=0;i<N;i++){
		printf("%d ",a[i]);
		//TODO
	}
	printf("\n");
}
void shellpaixu(int a[],int N){
	int inc,i,j;
	for(int inc=N/2;inc>0;inc/=2){//令初始增量为N/2 ,每一趟后除以2. 
		for(i=inc;i<N;i++){
			//希尔排序的复杂度依赖于增量序列
			//hibbard增量序列，sedgewick增量序列
			//不稳定 
			int t=a[i];
			for(j=i;j>=inc&&t<a[j-inc];j-=inc){
				a[j]=a[j-inc];
				//TODO
			}
			a[j]=t;
			//TODO
		}
		printarr(a,N);
		//TODO
	}
}
int main() {
	int a[13]={10,9,12,8,13,11,1,4,3,2,7,5,6};
	printarr(a,sizeof(a)/sizeof(int));
	shellpaixu(a,sizeof(a)/sizeof(int));
	printf("\n");
	printarr(a,sizeof(a)/sizeof(int));
    return 0;
}
