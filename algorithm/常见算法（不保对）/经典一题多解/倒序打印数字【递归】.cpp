#include <stdio.h>

void PrintOut(int N){
	if(N==0){
		return;
		//TODO
	} 
	printf("%d\n",N%10);
	PrintOut(N/10);
}
int main(){
	PrintOut(144556);
	return 0; 
}
