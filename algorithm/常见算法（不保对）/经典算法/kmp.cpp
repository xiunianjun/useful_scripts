#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void countSum(char* s){
	
}

void returnDis(int n,int arr[]){
	for(int i=0;i<n;i++){
		arr[i]=i-arr[i];
	}
}

int main(){
	char *s="ABABABAABABAAABABAA";
	char *p="ABABAAABABAA";
	int next[]={0,0,0,1,2,3,1,1,2,3,4,5,6};
	returnDis(sizeof(next)/sizeof(int),next);
	int j=0;
	for(int i=0;i<strlen(s);){
		if(s[i]!=p[j]){
			j-=next[j];
		}
		else{
			i++;
			j++;
			if(j>=strlen(p)){
				printf("Success!");
				break;
			}
		}
	}
    return 0;
}
