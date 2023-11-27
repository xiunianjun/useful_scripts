#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
/*
	为什么0-1背包和多重背包都需要从后往前扫，
	而完全背包需要从前往后扫：
	从后往前扫事实上是避免了重复选用同一个东西的情况
	不懂的话，你把代码中i=0那部分
	 dp[i]+=v[0];
	这句改成
	dp[i]=max(dp[i],dp[i-k*w[0]]+k*v[0]);
	康康改完之后i=0那行的结果你就懂了。
	完全背包不用限制东西的个数
	所以从前往后更新反而后面还能得到那件物品个数的最优解
	更加不复杂了 
*/


int max(int a,int b){
	return a>b?a:b;
}

int main(){
	int n,c;
	scanf("%d %d",&n,&c);
	int v[n],w[n]; 
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	} 
	for(int j=0;j<n;j++){
		scanf("%d",&w[j]);
	}
	int dp[c+1];
	for(int i=0;i<=c;i++){
		dp[i]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=w[i];j<=c;j++){	
			dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
		}
	}
	printf("%d",dp[c]);
	return 0;
}
