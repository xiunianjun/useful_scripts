#include <stdio.h>
#define N 51

int main()
{
	int a[N]={1};//��λ����ʹ�����鴢��λ�� 
	int index=0;//��¼����м�λ 
	for(int number=1;number<=40;number++){
		for(int i=number;i<=number;){//��������number 
			int c=0;//cΪ��λ����Ŀ 
			for(int j=0;j<=index;j++){ 
				a[j]*=i;//ÿ��λ������ 
				if(c!=0){//����i���ټ���ǰһλ�Ľ�λ 
					a[j]+=c;
					c=0;
					//TODO
				}
				if(a[j]>=10){//����λ��Ԫ��ֵ����10�����λ 
					if(j==index){//��������λ��λ�����λ++ 
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
		printf("%2d��= ",number);
		for(int m=index;m>=0;m--){
			printf("%d",a[m]);
			//TODO
		}
		printf("\n");
	}
    return 0;
}
