#include <stdio.h>

int FindMax(const int a[],int n){
	int maxSum=0;
	int curSum=0;
	for(int i=0;i<n;i++){
		curSum+=a[i];
		if(curSum>maxSum)
			maxSum=curSum;
		else if(curSum<0)
			curSum=0;
	}
	return maxSum;
}

int main(){
	int a[]={4,-3,5,-2,-1,2,6,-2};
	int result=FindMax(a,sizeof(a)/sizeof(a[0]));
	printf("%d",result);
	return 0;
} 
