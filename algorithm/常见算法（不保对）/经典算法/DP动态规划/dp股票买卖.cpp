#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int a,int b){
    return a>b?a:b;
}
int maxProfit(int* prices, int pricesSize){
    if(pricesSize==0)   return 0;
    int dp[pricesSize];
    int minPrice=prices[0];
    dp[0]=0;
    for(int i=1;i<pricesSize;i++){
        dp[i]=max(dp[i-1],prices[i]-minPrice);
        if(minPrice>prices[i]){
            minPrice=prices[i];
        }
    }
    return dp[pricesSize-1];
}
int main(){
	//[7,1,5,3,6,4]  5
	// [7,6,4,3,1]  0 
}
