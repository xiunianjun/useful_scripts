#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define INF 100000

/*
	ǰ���������������к�ֻ�ÿ���ǰһ���
	���Ҫ����ǰ�������
	��Ϊ������������к�Ԫ��ֻ������ѡȡ
	���Ըõ��״̬������һ���й� 
	����������е�Ԫ�ؿ��Դ�ԭ������Ծѡȡ
	���Ըõ�״̬��ֻ��õ���һ���йء�
	�õ����һ��״̬���������еĵ��е���һ�㡣 
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
