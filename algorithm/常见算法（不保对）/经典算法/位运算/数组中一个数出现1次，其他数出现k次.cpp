#include <stdio.h>

int main(){
	int a[]={5,1,1,3,
		2,2,4,3,3,2,
		7,7,7,6,6,6,8,
		8,4,4,5,8,9,5,1};
	//������9����һ�Σ��������ֳ���3�Ρ� 
	int size=sizeof(a)/sizeof(a[0]);
	int systerm[10]={0};
	int maxcount=0;
	for(int i=0;i<size;i++){
		for(int j=0;a[i]!=0;j++){
			systerm[j]+=a[i]%3;//systerm�����¼�ܵĽ������� 
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
	for(int i=maxcount;i>=0;i--){//��ÿ������λ�����ֽ���ȡ�࣬�õ�����n��3���� 
		sum*=3;
		systerm[i]%=3;
		sum+=systerm[i]; 
		//TODO
	}
	printf("%d",sum);
	
    return 0;
}
