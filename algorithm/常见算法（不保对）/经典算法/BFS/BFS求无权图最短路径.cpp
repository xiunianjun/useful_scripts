/*
��ʵ��ѭ���ڲ���������Ա�ǰ��ľ����С
ֻ���жϾ����Ƿ�Ϊ��ʼֵ����
��Ϊʵ����BFS��һ��һ��ɨ��
�����Խ��ɨ��Խ�������Ĵ���Խ��
�����һ��������Ȼ��֮����������������ǳ
���Զ�����Ȩͼ��˵ɨ������һ�ξ������·���� 
��Ҳ��ΪɶDijkstra�㷨�����õ�������
������С�ѡ����ȶ��С�
��ʵ�����ϻ���һ��BFS�� 
		for(int i=0;i<8;i++){
			if(graph[index][i]!=0){
				if(distance[i]==INF){
					distance[i]=distance[index]+1;
					pre[i]=index;
					AddQ(&queue,i);
					//TODO
				}
				//TODO
			}
			//TODO
		}
*/ 
#include<stdlib.h>
#include <stdio.h>
#define INF 10000
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

int main(){
	Queue queue;
	queue.front=NULL;
	queue.rear=NULL;
	int graph[8][8];
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			scanf("%d",&graph[i][j]);
			//TODO
		}
		//TODO
	}
	
	int distance[8];
	for(int i=0;i<8;i++){
		distance[i]=INF;
		//TODO
	} 
	distance[0]=0;
	int pre[8]={0};
	AddQ(&queue,0);
	while(queue.front&&queue.rear){
		int index=DeleteQ(&queue);
		for(int i=0;i<8;i++){
			if(graph[index][i]!=0){
				if(1+distance[index]<distance[i]){
					distance[i]=distance[index]+1;
					pre[i]=index;
					AddQ(&queue,i);
					//TODO
				}
				//TODO
			}
			//TODO
		}
		//TODO
	}
	for(int i=0;i<8;i++){
		printf("%d %d %d\n",i,pre[i],distance[i]);
		//TODO
	}
}

