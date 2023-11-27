/*
	顺式储存队列 
*/ 
#include <stdio.h>
#define MAXSIZE 10
typedef struct Queue{
	int front;//队列首 
	int rear;//队列末 
	int queue[MAXSIZE];
}Queue;
//求余实现循环队列的Add函数，简洁大方！ 
void AddQ(Queue* que,int number){
	if(((que->rear+1)%MAXSIZE==que->front)||(que->rear==MAXSIZE-2&&que->front==-1)){
		printf("The queue is full!\n");
		return;
		//TODO
	}
	que->rear=(que->rear+1)%MAXSIZE;
	que->queue[que->rear]=number;
}
//	if(que->front-que->rear==1){
//		printf("The que is full!\n");
//		return;
//		//TODO
//	}
//	if(que->rear==MAXSIZE-1){
//		if(que->front==0){
//			printf("The que is full!\n");
//			return;
//			//TODO
//		}
//		que->queue[0]=number;
//		que->rear=0;
//		//TODO
//	}
//	else if(que->rear==MAXSIZE-2){
//		if(que->front==-1){
//			printf("The que is full!\n");
//			return;
//			//TODO
//		}
//		que->queue[++(que->rear)]=number;
//		//TODO
//	}
//	else{
//		que->queue[++(que->rear)]=number;
//	}


void Print(Queue *que){
	if(que->front<que->rear){
		for(int i=que->front+1;i<=que->rear;i++){
			printf("%d ",que->queue[i]);
			//TODO
		}
		//TODO
	}
	else if(que->front>=que->rear){
		for(int i=que->front+1;i<MAXSIZE;i++){
			printf("%d ",que->queue[i]);
			//TODO
		}
		for(int i=0;i<=que->rear;i++){
			printf("%d ",que->queue[i]);
			//TODO
		}
		//TODO
	}
}

int DeleteQ(Queue *que){
	if(que->rear==que->front){
		printf("The queue is empty!\n");
		return EOF;
	}
	que->front=(que->front+1)%MAXSIZE;
	return que->queue[que->front];
}

int main(){
	Queue que;
	que.front=-1;
	que.rear=-1;
	DeleteQ(&que);
	for(int i=0;i<=MAXSIZE+1;i++){
		AddQ(&que,i);
		if(i==7){
			DeleteQ(&que);
			DeleteQ(&que);
			//TODO
		}
		//TODO
	}
	Print(&que);
	return 0; 
}
