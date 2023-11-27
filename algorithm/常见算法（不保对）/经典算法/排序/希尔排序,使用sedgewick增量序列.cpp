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
	int Sedgewick[] = {260609,146305,64769,36289,16001,8929,
					3905,2161,929, 505,209, 109, 41,
					 19, 5, 1, 0};//或者gn+1=3gn+1 
	int si;
	for(si=0;Sedgewick[si]>=N;si++);//用来得到一个初始的恰当的inc。 
	for(int inc=Sedgewick[si];inc>0;inc=Sedgewick[++si]){
		for(i=inc;i<N;i++){
			int t=a[i];
			for(j=i;j>=inc&&t<a[j-inc];j-=inc){
				int temp=a[j];
				a[j]=a[j-inc];
				a[j-inc]=temp;
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
