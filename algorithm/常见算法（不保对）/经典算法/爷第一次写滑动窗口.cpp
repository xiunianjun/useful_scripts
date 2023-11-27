#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 128
bool IsIn(int a[],int index1,int index2,char*s){
    int b[SIZE];
    for(int i=0;i<SIZE;i++){
		b[i]=0;
	}
    for(int i=index1;i<=index2;i++){
        b[s[i]]++;
    }
    for(int i=0;i<SIZE;i++){
        if(b[i]<a[i])   return false;
    }
    return true;
}
bool IsOk(int a[],int b[]){
    for(int i=0;i<SIZE;i++){
        if(b[i]<a[i])   return false;
    }
    return true;    
}
char * minWindow(char * s, char * t){
    if(s==NULL||t==NULL||s==""||t=="")  return "";
    if(strlen(s)<strlen(t)) return "";
    int a[SIZE];
    for(int i=0;i<SIZE;i++){
		a[i]=0;
	}
    for(int i=0;i<strlen(t);i++){
        a[t[i]]++;
    }
    if(strlen(s)==strlen(t)){
        if(IsIn(a,0,strlen(s)-1,s)){
            return s;
        }
        else{
            return "";
        }
    }
    int b[SIZE];
    for(int i=0;i<SIZE;i++){
		b[i]=0;
	}
    int left=0;
    int right=0;
    int resultL=0;
    int resultR=1000000;
    while(right<strlen(s)){
        b[s[right]]++;
        while(IsOk(a,b)){
            if(resultR-resultL>right-left&&right-left+1>=strlen(t)){
                resultL=left;
                resultR=right;
            }
            b[s[left]]--;
            left++;
        }
        right++;
    }
    if(resultR-resultL==1000000)    return "";
    char* result=(char*)malloc(sizeof(char)*(resultR-resultL+1+1));
    int count=0;
    for(int i=resultL;i<=resultR;i++){
        result[count++]=s[i];
    }
    result[count]='\0';
    return result;
}
int main(){
	char*s = "a",* t = "b";
	char* result=minWindow(s,t);
	printf("%s",result);
}
