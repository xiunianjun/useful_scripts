#include <stdio.h>
#define N 1000000007

int main (void)
{
	int n=0;
	scanf("%d",&n);
	int c[n+1][n+1]={0}; 
	c[1][0]=c[1][1]=1;
	for(int i=2;i<=n;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%N;
			//TODO
		}
	}
	printf("%d",c[n-1][(n-1)/2]);
    return 0;
}
