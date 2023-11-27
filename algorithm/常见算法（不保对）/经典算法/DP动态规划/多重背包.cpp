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
	int v[n],w[n],num[n];
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	int dp[c+1];
	for(int i=0;i<=c;i++){
		dp[i]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=c;j>=0;j--){
			for(int k=0;k<num[i];k++){
				if(j>=k*w[i]){
					dp[j]=max(dp[j-k*w[i]]+k*v[i],dp[j]);
					//TODO
				}
			}
		}
	}
	printf("%d",max(dp[0],dp[c]));
	return 0;
}
