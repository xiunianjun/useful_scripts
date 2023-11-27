#include<stdlib.h>
#include <stdio.h>
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

int IsVisit(int visit[]){
	for(int i=0;i<3;i++){
		if(visit[i]==0){
			return 0;
			//TODO
		}
		//TODO
	}
	return 1;
}

void BFS(int graph[3][3],int visit[]){
	Queue queue;
	queue.front=NULL;
	queue.rear=NULL;
	AddQ(&queue,0);
	int temp=0;
	while(!IsVisit(visit)&&temp!=EOF){
		temp=DeleteQ(&queue);
		visit[temp]=1;
		printf("%d ",temp);
		for(int i=temp+1;i<3;i++){
			if(visit[i]!=1&&graph[0][i]==1){
				AddQ(&queue,i);
				//TODO
			}
		}
	}
}

int main(){
	int graph[3][3]={0,1,1,1,0,1,1,1,0};
	int visit[3]={0};
	BFS(graph,visit);
	return 0; 
}
