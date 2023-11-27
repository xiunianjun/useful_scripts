#include <stdio.h>

void BubbleSort(int b[],int n){
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<n-1;j++){
			if(b[j]<b[j+1]){
				int temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
				//TODO
			}
			//TODO
		}
		//TODO
	}
}

int main(){
	int a[10];
	for(int i=0;i<10;i++){
		a[i]=10-i;
		//TODO
	}
	int k=6;
	int b[10];
	for(int i=0;i<k;i++){
		b[i]=a[9-i];
		//TODO
	}
	BubbleSort(b,k);
	for(int i=0;i<10-k;i++){
		if(a[i]>b[k-1]){
			int j=k-1;
			for(j=k-1;j>=0;j--){
				if(a[i]>b[j]){
					b[j]=b[j-1];
					//TODO
				}
				else{
					break;
				}
				//TODO
			}
			b[j+1]=a[i];
			//TODO
		}
		//TODO
	}
	for(int i=0;i<k;i++){
		printf("%d ",b[i]);
		//TODO
	}
	BubbleSort(a,10);
	printf("\n%d",a[k-1]);
	return 0; 
}
