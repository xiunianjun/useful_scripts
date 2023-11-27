#include<stdio.h>

//非递归算法，使用二进制原理 
//具体原理见
//https://blog.csdn.net/IOS9527o/article/details/52818663?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164154427116780255256007%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164154427116780255256007&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-52818663.pc_search_insert_es_download&utm_term=%E5%BF%AB%E9%80%9F%E6%B1%82%E5%B9%82%E9%9D%9E%E9%80%92%E5%BD%92&spm=1018.2226.3001.4187 
double Pow(double x, int n)
{
    double result = 1;
    while (n)
    {
        if (n & 1)        // 等价于 if (n % 2 != 0)
            result *= x;
        n >>= 1;        //按位右移1位
        x *= x;
    }
    return result;
}
//递归算法
double PPow(double x,int n){
	if(n==0){
		return 1;
		//TODO
	}
	if(n==1){
		return x;
		//TODO
	}
	if(n&1==true){
		return PPow(x*x,n/2)*x;
		//TODO
	}
	else{
		return PPow(x*x,n/2);
		//TODO
	}
} 

int main() {
	printf("%f  %f",Pow(2,9),PPow(2,9));
	return 0;
}
