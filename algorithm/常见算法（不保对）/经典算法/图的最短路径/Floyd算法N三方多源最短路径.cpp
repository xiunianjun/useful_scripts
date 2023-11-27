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
		差不多意思就是给你随便两个点ij
		你经过最多k个的点【0~k编号】到达彼此所需的最短路径
		k增大到SIZE时所得的就是最最短路径
		它们间有个递推方式可以求 
	*/ 
	//外层循环表示经历k次迭代 
	//联想关系闭包
	//一次迭代表示经过k条边可以到达另一条点 
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
			巧妙的是他那个内层循环 
			ak（ij）=ak-1（ik）+ak-1（kj）
			其中ak和ak-1的表达方式
	*/
}
