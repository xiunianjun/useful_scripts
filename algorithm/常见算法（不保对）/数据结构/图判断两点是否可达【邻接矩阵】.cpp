#include <stdio.h>
#include <stdlib.h>
#define M 6

int DFS(int graph[M][M],int k1,int k2,int visit[]){
	visit[k1]=1;
	if(k1==k2){
		return 1;
		//TODO
	}
	for(int i=0;i<M;i++){
		if(graph[k1][i]!=0&&!visit[i]){
			return DFS(graph,i,k2,visit);
		}
	}
	return 0;
}

int main(){
	int graph[M][M];
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&graph[i][j]);
			//TODO
		}
		//TODO
	}
	int visit[M]={0};
	int k1,k2;
	scanf("%d %d",&k1,&k2);
	int IsOk=DFS(graph,k1,k2,visit);
	printf("%d",IsOk);
	return 0; 
}
