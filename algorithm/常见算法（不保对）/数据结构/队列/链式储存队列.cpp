/*
	¡¥ Ω¥¢¥Ê∂”¡– 
*/
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

int main(){
	Queue queue;
	queue.front=NULL;
	queue.rear=NULL;
	for(int i=0;i<10;i++){
		AddQ(&queue,i);
		//TODO
	}
	PrintQ(&queue);
	printf("\n");
	int c;
	for(int i=0;i<11;i++){
		if((c=DeleteQ(&queue))!=EOF){
			printf("The out number is %d.\n",c);
			//TODO
		}
		PrintQ(&queue);
		printf("\n");
		//TODO
	}
	free(queue.front);
	free(queue.rear);
	return 0; 
}
