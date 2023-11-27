#include <stdio.h>
int main()
{
	int a=0,b=0;
	scanf("%d %d",&a,&b);
	int yue=1;
	int i=1;
	int min;
	if(a>b){
		min=b;
		//TODO
	}
	if(a<b){
		min=a;
		//TODO
	}
	while(i<=min){
		if(a%i==0){
			if(b%i==0){
				yue=i;
				
			}
		}
		i++;
	}
	printf("%d",yue);
	
	return 0; 
} 
