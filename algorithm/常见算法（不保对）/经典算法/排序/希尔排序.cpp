#include <stdio.h>
void printarr(int a[],int N){
	for(int i=0;i<N;i++){
		printf("%d ",a[i]);
		//TODO
	}
	printf("\n");
}
void shellpaixu(int a[],int N){
	int inc,i,j;
	for(int inc=N/2;inc>0;inc/=2){//���ʼ����ΪN/2 ,ÿһ�˺����2. 
		for(i=inc;i<N;i++){
			//ϣ������ĸ��Ӷ���������������
			//hibbard�������У�sedgewick��������
			//���ȶ� 
			int t=a[i];
			for(j=i;j>=inc&&t<a[j-inc];j-=inc){
				a[j]=a[j-inc];
				//TODO
			}
			a[j]=t;
			//TODO
		}
		printarr(a,N);
		//TODO
	}
}
int main() {
	int a[13]={10,9,12,8,13,11,1,4,3,2,7,5,6};
	printarr(a,sizeof(a)/sizeof(int));
	shellpaixu(a,sizeof(a)/sizeof(int));
	printf("\n");
	printarr(a,sizeof(a)/sizeof(int));
    return 0;
}
