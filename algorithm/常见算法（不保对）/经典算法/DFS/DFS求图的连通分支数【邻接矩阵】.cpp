/*
	DFS��ͼ����ͨ��֧�� 
*/
#include <stdio.h>
#define N 1
//���Ƿ����ж��㶼�����ʱ�ǹ� 
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
//DFS���� 
void DFS(int graph[N][N],int number,int visit[]){
	//��Ǵ���ĵ�һ��������� 
	visit[number]=1;
	//�߽�������Խ��
	if(number==N-1){
		return;
		//TODO
	}
	//��ÿ�����Ѱ�����������ĵ� 
	for(int i=0;i<N;i++){
		if(graph[number][i]!=1000&&visit[i]==0&&i!=number){
			DFS(graph,i,visit);
			//TODO
		}
		//TODO
	}
}

int main(){
	//�����ڽӾ��� 
	int graph[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&graph[i][j]);
			//TODO
		}
		//TODO
	}
	
	int visit[N]={0};
	//�������� 
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
