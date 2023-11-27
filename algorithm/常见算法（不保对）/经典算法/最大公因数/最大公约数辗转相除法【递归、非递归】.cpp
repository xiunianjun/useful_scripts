#include <stdio.h>
//µÝ¹é°æ 
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
//·ÇµÝ¹é°æ 
//int gcd(int a,int b){
//	while(b!=0)
//    {	
//	    int t=0;
//		t=a%b;
//		a=b;
//		b=t; 
//    }  
//    return a;
//} 
int main()
{
	printf("%d",gcd(30,5));
}
