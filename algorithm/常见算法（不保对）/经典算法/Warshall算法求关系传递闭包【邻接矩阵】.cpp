/*
	Warshall�㷨���ϵ���ݱհ� 
*/
#include <stdio.h>
#define N 6
int main(){
	int M[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&M[i][j]);
		} 
		//TODO
	}
	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			//i->k->j  ���i��k���бߣ���i��j���бߣ���j��k�ض��б� 
			if(M[i][k]==1){
				for(int j=0;j<N;j++){
					if(M[i][j]==1){
						M[k][j]=1;
						//TODO
					}
					//TODO
				}
			}
			//TODO
		}
		//TODO
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%d ",M[i][j]);
		} 
		printf("\n");
		//TODO
	}
	return 0; 
}
