#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
/*
	Ϊʲô0-1�����Ͷ��ر�������Ҫ�Ӻ���ǰɨ��
	����ȫ������Ҫ��ǰ����ɨ��
	�Ӻ���ǰɨ��ʵ���Ǳ������ظ�ѡ��ͬһ�����������
	�����Ļ�����Ѵ�����i=0�ǲ���
	 dp[i]+=v[0];
	���ĳ�
	dp[i]=max(dp[i],dp[i-k*w[0]]+k*v[0]);
	��������֮��i=0���еĽ����Ͷ��ˡ�
	��ȫ�����������ƶ����ĸ���
	���Դ�ǰ������·������滹�ܵõ��Ǽ���Ʒ���������Ž�
	���Ӳ������� 
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
