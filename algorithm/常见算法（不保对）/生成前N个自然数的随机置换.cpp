#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
void Swap(int*a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int main(){
	int N;
	scanf("%d",&N);
	int a[N];
	srand((unsigned int)time(NULL));
	for(int i=0;i<N;i++){
		a[i]=i+1;
		//TODO
	}
	for(int i=1;i<N;i++){
		int random=rand()%i;
		Swap(&a[i],&a[random]);
		//TODO
	}
	for(int i=0;i<N;i++){
		printf("%d ",a[i]);
		//TODO
	}
	return 0;
} 
