#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//µü´ú·¨
long long FastPower(int a,int e){
	int result=1;
	while(e>0){
		if((e&1)==1){
			result*=a;
		}
		a*=a;
		e=(e>>1);
	}
	return result;
} 
//µÝ¹é·¨ 
//long long FastPower(int a,int e){
//	if(e==0)	return 1;
//	int result=FastPower(a,e>>1);
//	result*=result;
//	return e&1==1?result*a:result;
//}

int main(){
	printf("%d",FastPower(3,3));
}
