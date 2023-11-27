#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define INF 100000

/*
	前面的最大连续子序列和只用考虑前一项，但
	这个要考虑前面所有项：
	因为最大连续子序列和元素只能连续选取
	所以该点的状态与它上一点有关 
	而这个子序列的元素可以从原序列跳跃选取
	所以该点状态不只与该点上一点有关。
	该点的上一个状态可能是已有的点中的任一点。 
*/ 

int max(int a,int b){
	return a>b?a:b;
}

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	int dp[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		dp[i]=1;
	} 
	int result=1;
	for(int i=1;i<n;i++){
		for(int j=1;j<i;j++){
			if(a[j]<a[i])
				dp[i]=max(dp[i],dp[j]+1);
			//TODO
		}
		if(dp[i]>result){
			result=dp[i];
			//TODO
		}
	}
	printf("%d",result);
	return 0;
}
