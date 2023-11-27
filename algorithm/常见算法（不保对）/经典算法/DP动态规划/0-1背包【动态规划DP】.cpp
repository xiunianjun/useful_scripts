#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
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
	int dp[n+1][c+1];
	for(int i=0;i<n;i++){
		dp[i][0]=0;
	}
	for(int i=0;i<c;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=w[i-1];j<=c;j++){
			dp[i][j]=max(dp[i-1][j-w[i-1]]+v[i-1],dp[i-1][j]);
		}
	}
	printf("%d",dp[n][c]);
	return 0;
}
