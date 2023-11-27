#include <stdio.h>

int main(){
	int a[]={5,1,1,3,
		2,2,4,3,3,2,
		7,7,7,6,6,6,8,
		8,4,4,5,8,9,5,1};
	//不妨令9出现一次，其他数字出现3次。 
	int size=sizeof(a)/sizeof(a[0]);
	int systerm[10]={0};
	int maxcount=0;
	for(int i=0;i<size;i++){
		for(int j=0;a[i]!=0;j++){
			systerm[j]+=a[i]%3;//systerm数组记录总的进制数字 
			a[i]/=3;
			if(j>maxcount){
				maxcount=j;
				//TODO
			}
			//TODO
		}
		//TODO
	}
	int sum=0;
	for(int i=maxcount;i>=0;i--){//对每个进制位数数字进行取余，得到的是n的3进制 
		sum*=3;
		systerm[i]%=3;
		sum+=systerm[i]; 
		//TODO
	}
	printf("%d",sum);
	
    return 0;
}
