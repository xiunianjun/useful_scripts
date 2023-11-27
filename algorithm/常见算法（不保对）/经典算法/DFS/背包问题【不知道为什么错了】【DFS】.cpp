#include <stdio.h>
#include <stdlib.h>

/*
TestCase:
5 8
3 5 1 2 2
4 5 2 1 3

correct output:10
my output:8???
*/

void ValueSum(int max,int value[],int weight[],int n,int j,int sumV,int sumW,int* maxValue){
	if(j==n){
		return;
		//TODO
	}
	ValueSum(max,value,weight,n,j+1,sumV,sumW,maxValue);
	if(sumW+weight[j]<=max){
		if(sumV+value[j]>*maxValue){
			*maxValue=sumV+value[j];
			sumV+=value[j];
			sumW+=weight[j];
			//TODO
		}
		ValueSum(max,value,weight,n,j+1,sumV,sumW,maxValue);
		//TODO
	}
	
}

int main(){
	int n,max;
	scanf("%d %d",&n,&max);
	int value[n];
	int weight[n];
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);
		//TODO
	}
	for(int i=0;i<n;i++){
		scanf("%d",&value[i]);
		//TODO
	}
	int maxValue=0;
	ValueSum(max,value,weight,n,0,0,0,&maxValue);
	printf("%d",maxValue);
	return 0; 
}
