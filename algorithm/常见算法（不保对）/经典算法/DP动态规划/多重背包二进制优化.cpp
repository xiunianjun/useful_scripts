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
	int vv[20],ww[20];
	int cnt=0;
	for(int i=0;i<n;i++){
		int k=1;
		for(k=1;k<num[i];k=(k<<1)){
			vv[cnt]=k*v[i];
			ww[cnt++]=k*w[i];
			num[i]-=k;
		}
		if(k){
			vv[cnt]=k*v[i];
			ww[cnt++]=k*w[i];
		}
	}
	int dp[c+1];
	for(int i=0;i<=c;i++){
		dp[i]=0;
	}
	for(int i=0;i<cnt;i++){
		for(int j=c;j>=0;j--){
			if(j>=ww[i]){
				dp[j]=max(dp[j-ww[i]]+vv[i],dp[j]);
				//TODO
			}
		}
	}
	printf("%d",max(dp[0],dp[c]));
	return 0;
}
