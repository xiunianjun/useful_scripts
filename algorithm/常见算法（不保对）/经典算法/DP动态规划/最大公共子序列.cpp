#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define INF 100000
/*
	���ǵ�a�ĵ�i����b�ĵ�j��Ϊֹ��������г���
	up�ã�
	����Ϊʲô�༭�����Ǵ����桢��ߡ���������ֵѡȡǰһ��
	״̬��
	��������������Ǵ�������������ֵ��ѡȡǰһ��״̬�أ�
	
	����Ϊ������������Ǳ�
	�����Ǹ�״̬�϶������������״̬֮һֵ��ͬ��
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
