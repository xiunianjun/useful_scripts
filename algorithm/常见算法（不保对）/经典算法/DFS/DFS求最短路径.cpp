#include<stdlib.h>
#include <stdio.h>
#define SIZE 8

int DFS(int graph[SIZE][SIZE],int point1,int point2){
	if(point1==point2){
		return 0;
		//TODO
	}
	int min=10000;
	//注意此处条件，不能用visit判断 
	for(int i=point1+1;i<SIZE;i++){
		if(graph[point1][i]!=0){
			int temp=graph[point1][i]+DFS(graph,i,point2);
			if(temp<min){
				min=temp;
				//TODO
			}
			//TODO
		}
		//TODO
	}
	return min;
}

int main(){
	int graph[SIZE][SIZE];
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			scanf("%d",&graph[i][j]);
			//TODO
		}
		//TODO
	}
	int result=DFS(graph,0,7);
	printf("%d",result);
	return 0;
}
