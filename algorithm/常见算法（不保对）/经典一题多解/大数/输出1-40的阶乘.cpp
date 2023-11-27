#include <stdio.h>
#define N 51

int main()
{
	int a[N]={1};//数位过大，使用数组储存位数 
	int index=0;//记录最大有几位 
	for(int number=1;number<=40;number++){
		for(int i=number;i<=number;){//不断增长number 
			int c=0;//c为进位的数目 
			for(int j=0;j<=index;j++){ 
				a[j]*=i;//每个位数都乘 
				if(c!=0){//乘上i后再加上前一位的进位 
					a[j]+=c;
					c=0;
					//TODO
				}
				if(a[j]>=10){//若数位上元素值大于10，则进位 
					if(j==index){//如果在最高位进位，最大几位++ 
						index++;
						//TODO
					}
					c=a[j]/10;
					a[j]%=10;
					//TODO
				}
				
				//TODO
			}
			i++;
		}
		printf("%2d！= ",number);
		for(int m=index;m>=0;m--){
			printf("%d",a[m]);
			//TODO
		}
		printf("\n");
	}
    return 0;
}
