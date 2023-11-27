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
	int dp[c+1];
	for(int i=0;i<=c;i++){
		dp[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=c;j>=w[i-1];j--){
			dp[j]=max(dp[j-w[i-1]]+v[i-1],dp[j]);
		}
	}
	printf("%d",dp[c]);
	return 0;
}
