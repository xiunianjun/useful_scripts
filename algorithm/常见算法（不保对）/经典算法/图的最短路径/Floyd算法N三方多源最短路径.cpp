#include<stdlib.h>
#include <stdio.h>
#define INF 10000
#define SIZE 8

int** Floyd(int** graph,int n){
	int** distance=(int**)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++){
		distance[i]=(int*)malloc(sizeof(int)*n);
		for(int j=0;j<n;j++){
			distance[i][j]=graph[i][j];
			if(graph[i][j]==0){
				if(i!=j){
					distance[i][j]=INF;
				}
			}
		}
	} 
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int t=distance[i][k]+distance[k][j];
				if(t<distance[i][j]){
					distance[i][j]=t;
				}
			}
		}
	}
	return distance;
} 

int main(){
	int distance[SIZE][SIZE];
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			scanf("%d",&distance[i][j]);
			if(distance[i][j]==0){
				distance[i][j]=INF;
				//TODO
			}
			//TODO
		}
		//TODO
	}
	/*
		�����˼���Ǹ������������ij
		�㾭�����k���ĵ㡾0~k��š�����˴���������·��
		k����SIZEʱ���õľ��������·��
		���Ǽ��и����Ʒ�ʽ������ 
	*/ 
	//���ѭ����ʾ����k�ε��� 
	//�����ϵ�հ�
	//һ�ε�����ʾ����k���߿��Ե�����һ���� 
	for(int k=0;k<SIZE;k++){
		for(int i=0;i<SIZE;i++){
			for(int j=0;j<SIZE;j++){
				if(distance[i][j]>distance[i][k]+distance[k][j]){
					distance[i][j]=distance[i][k]+distance[k][j];
					//TODO
				}
				//TODO
			}
			//TODO
		}
		//TODO
	}
	/*
			����������Ǹ��ڲ�ѭ�� 
			ak��ij��=ak-1��ik��+ak-1��kj��
			����ak��ak-1�ı�﷽ʽ
	*/
}
