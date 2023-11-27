/*
	DFS求图的连通分支数 
*/
#include <stdio.h>
#define N 1
//看是否所有顶点都被访问标记过 
int IsVisit(int visit[]){
	for(int i=0;i<N;i++){
		if(visit[i]==0){
			return 0;
			//TODO
		}
		//TODO
	}
	return 1;
}
//DFS搜索 
void DFS(int graph[N][N],int number,int visit[]){
	//标记传入的第一个搜索结点 
	visit[number]=1;
	//边界条件：越界
	if(number==N-1){
		return;
		//TODO
	}
	//对每个结点寻找与他关联的点 
	for(int i=0;i<N;i++){
		if(graph[number][i]!=1000&&visit[i]==0&&i!=number){
			DFS(graph,i,visit);
			//TODO
		}
		//TODO
	}
}

int main(){
	//输入邻接矩阵 
	int graph[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&graph[i][j]);
			//TODO
		}
		//TODO
	}
	
	int visit[N]={0};
	//进行搜索 
	int count=0;
	for(int i=0;i<N&&!IsVisit(visit);i++){
		if(visit[i]==1){
			continue;
			//TODO
		}
		DFS(graph,i,visit);
		count++;
		//TODO
	}
	printf("%d",count);
	return 0; 
}
