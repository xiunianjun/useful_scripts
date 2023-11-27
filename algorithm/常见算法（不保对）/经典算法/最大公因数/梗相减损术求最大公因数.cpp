#include <stdio.h>
#include <math.h>

int max(int a,int b){
	return a>b?a:b;
} 

int min(int a,int b){
	return a<b?a:b;
}
//递归  为啥人家就这么简洁明了呢 
//int gcd(int a,int b){
//    if(a==b)return a;
//    else if(a>b)a-=b;
//    else b-=a;
//    return gcd(a,b);
//}

//int main()
//{　
//    int a,b;　
//    cin>>a>>b;　
//    while(a != b)　
//    {　
//        if(a > b)　
//            a -= b;　
//        else　
//            b -= a;　
//     }　
//     cout<<a<<endl;　
//     return 0;　
//}

int FindGongyinshu(int M,int N){
	int count=0;
	while(M%2==0&&N%2==0){
		M/=2,N/=2;
		count++;
		//TODO
	}
	int result=M;
	while(result!=0){
		result=max(result,N)-min(result,N);
		N=min(M,N) ;
		M=result;
	}
	return N*pow(2,count);
}

int main(){
	printf("%d",FindGongyinshu(104,260));
	return 0;
} 
