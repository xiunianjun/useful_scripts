#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#define INF 10000

int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int toy[n];
	for(int i=0;i<n;i++){
		toy[i]=0;
		int a;
		scanf("%d",&a);
		while(a>0){
			int kind;
			scanf("%d",&kind);
			toy[i]|=(1<<(kind-1));
			a--;
		}
	}
	int dp[2][m+1];
	for(int i=0;i<=m;i++){
		dp[0][i]=0;
		dp[1][i]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=m;j>=1;j--){
			if((toy[i]&dp[1][j-1])==0){
				dp[1][j]=(dp[1][j-1]|toy[i]);
				dp[0][j]=dp[0][j-1]+1;
			}
		}
	}
	printf("%d",dp[0][m]);
	return 0;
}
