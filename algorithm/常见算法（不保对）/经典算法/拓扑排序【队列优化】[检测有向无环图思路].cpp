#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <queue>
#include<string.h>
#define INF 10000
#define SIZE 8
using namespace std; 

//没调过，不知道对不对 
int* countInDegree(int** graph,int n){
	int* degree=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(graph[j][i]!=0){
				degree[i]++;
			}
		}
	}
	return degree;
} 

void topoOrder(int** graph,int n){
	int* inDegree=countInDegree(graph,n);
	queue<int> q;
	for(int i=0;i<n;i++){
		if(inDegree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int t=q.front();
		q.pop();
		printf("%d ",q);
		for(int i=0;i<n;i++){
			if(graph[t][i]!=0){
				inDegree[i]--;
				graph[t][i]--;
				if(inDegree[i]==0){
					q.push(i);
				}
			}
		}
	}
}

typedef struct QNode{
	int value;
	QNode*next;
}QNode;

typedef struct Queue{
	QNode*front;
	QNode*rear;
}Queue;

QNode* CreateQNode(){
	QNode* q=(QNode*)malloc(sizeof(QNode));
	q->value=0;
	q->next=NULL;
	return q; 
}

void AddQ(Queue*queue,int number){
	QNode*q=CreateQNode();
	q->value=number;
	if(!(queue->front)&&!(queue->rear)){
		queue->front=queue->rear=q;
	}
	else{
		queue->rear->next=q;
		queue->rear=q;
	}
}

void PrintQ(Queue*queue){
	if(queue->front==NULL){
		printf("The queue is Null!\n");
		return;
		//TODO
	}
	QNode* q=queue->front;
	while(q){
		printf("%d ",q->value);
		q=q->next;
		//TODO
	}
}

int DeleteQ(Queue*queue){
	if(queue->front==NULL){
		printf("The queue is Null!\n");
		return EOF;
		//TODO
	}
	if(queue->front==queue->rear){
		queue->rear=NULL;
		//TODO
	}
	QNode*q=queue->front;
	int number=q->value;
	queue->front=(queue->front)->next;
	free(q);
	return number;	
}

int IsEmpty(Queue queue){
	if(queue.front==NULL){
		return 1;
		//TODO
	}
	return 0;
}

int IsHead(int graph[][SIZE],int index){
	for(int j=0;j<SIZE;j++){
		if(graph[j][index]!=0){
			return 0;
			//TODO
		}
	}
	return 1;
}

int main(){
	int graph[SIZE][SIZE];
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			scanf("%d",&graph[i][j]);
		}
		//TODO
	}
	
	
	Queue queue;
	queue.front=NULL;
	queue.rear=NULL;
	
	//如果需要判断有无环，需要一个visit数组
	int visit[SIZE]; 
	for(int i=0;i<SIZE;i++){
		visit[i]=0;
		//如果入度为0 则入队
		if(IsHead(graph,i)){
			AddQ(&queue,i);
		}
	}
	while(!IsEmpty(queue)){
		int v=DeleteQ(&queue);
		visit[v]=1;
		for(int j=0;j<SIZE;j++){
			if(graph[v][j]!=0){
				graph[v][j]--;
				if(graph[v][j]==0&&IsHead(graph,j)){
					AddQ(&queue,j);
				}
			}
		}
	}
	for(int i=0;i<SIZE;i++){
		if(visit[i]==0){
			printf("有环");
			break;
		}
	}
}
