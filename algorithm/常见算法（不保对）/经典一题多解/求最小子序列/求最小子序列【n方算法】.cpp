#include <stdio.h>

int FindMax(const int a[],int n){
	int maxSum=0;
	int curSum=0;
	for(int i=0;i<n;i++){
		curSum=0;
		for(int j=i;j<n;j++){
			curSum+=a[j];
			if(curSum>maxSum){
				maxSum=curSum;
				//TODO
			}
			//TODO
		}
	} 
	return maxSum;
}

int main(){
	int a[]={4,-3,5,-2,-1,2,6,-2};
	int result=FindMax(a,sizeof(a)/sizeof(a[0]));
	printf("%d",result);
	return 0;
} 
