#include <stdio.h>
/*
	比如X=3,F(X)=4X^4+8X^3+X+2
	输入：
		5
		2 1 0 8 4
		3
	输出：
		545 
*/


int main(){
	int N;
	scanf("%d",&N);
	int a[N];
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
		//TODO
	}
	int x;
	scanf("%d",&x);
	int poly=0;
	for(int i=N-1;i>=0;i--){
		poly=x*poly+a[i];
		//TODO
	}
	printf("%d",poly);
	return 0;
} 
