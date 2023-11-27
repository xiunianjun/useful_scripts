#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define INF 100000
/*
	考虑到a的第i个和b的第j个为止最大子序列长度
	up好，
	请问为什么编辑距离是从上面、左边、左上三个值选取前一个
	状态，
	而最长公共子序列是从上面和左边两个值中选取前一个状态呢？
	
	是因为最长公共子序列那边
	左上那个状态肯定与左和上两个状态之一值相同吗
*/

int max(int a,int b){
	return a>b?a:b;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n];
	int b[m];
	int dp[n][m];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	} 
	for(int i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	for(int i=0;i<=m;i++){
		dp[0][i]=0;
	}
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
				//TODO
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
			//TODO
		}
		//TODO
	}
	printf("%d",dp[n][m]);
	return 0;
}
