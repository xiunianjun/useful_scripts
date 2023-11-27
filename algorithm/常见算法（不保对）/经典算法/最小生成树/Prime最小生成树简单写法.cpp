#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 1000000

int Prime(int** graph,int n){
	int visit[n];
	int dis[n];
	for(int i=0;i<n;i++){
		visit[i]=0;
		dis[i]=graph[0][i];
	}
	int ans=0;
	visit[0]=1;
	for(int x=0;x<n;x++){
		int min=INF;
		int minIndex=-1;
		for(int i=0;i<n;i++){
			if(visit[i]!=1&&dis[i]<min){
				min=dis[i];
				minIndex=i;
			}
		}
		if(min<INF)
			ans+=min;
		visit[minIndex]=1;
		for(int i=0;i<n;i++){
			if(visit[i]!=1&&dis[i]>graph[minIndex][i]){
				dis[i]=graph[minIndex][i];
			}
		}
	}
	return ans;
}

int main(){
	int** graph=(int**)malloc(sizeof(int*)*8);
	int visit[8]={0};
	for(int i=0;i<8;i++){
		graph[i]=(int*)malloc(sizeof(int)*8);
		for(int j=0;j<8;j++){
			scanf("%d",&graph[i][j]);
			if(graph[i][j]==0){
				graph[i][j]=INF;
			}
		}
	}
	visit[0]=1;
	printf("%d",Prime(graph,8)); 
    return 0;
}
