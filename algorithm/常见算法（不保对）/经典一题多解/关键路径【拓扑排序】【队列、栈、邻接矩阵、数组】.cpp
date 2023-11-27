#include<stdlib.h>
#include <stdio.h>
#define INF 10000
#define SIZE 9
typedef struct Point{
	int point;
	int earlist;
	int latest;
}Point;
typedef struct Node{
	Point value;
	Node*bottom;
}Node;

typedef struct Stack{
	int lenth;
	Node* top;
}Stack;

Node* CreateStackNode(){
	Node * p=(Node*)malloc(sizeof(Node));
	p->bottom=NULL;
	return p;
}

void Push(Stack *stack,Point point){
	Node *p=CreateStackNode();
	p->value=point;
	p->bottom=(*stack).top;
	(*stack).lenth++;
	(*stack).top=p;
}

Point Pop(Stack *stack){
	Node* p=(*stack).top;
	Point number=(*stack).top->value;
	(*stack).top=(*stack).top->bottom;
	(*stack).lenth--;
	return number;
}
typedef struct QNode{
	Point value;
	QNode*next;
}QNode;

typedef struct Queue{
	QNode*front;
	QNode*rear;
}Queue;

QNode* CreateQNode(){
	QNode* q=(QNode*)malloc(sizeof(QNode));
	q->next=NULL;
	return q; 
}

void AddQ(Queue*queue,Point point){
	QNode*q=CreateQNode();
	q->value=point;
	if(!(queue->front)&&!(queue->rear)){
		queue->front=queue->rear=q;
	}
	else{
		queue->rear->next=q;
		queue->rear=q;
	}
}

Point DeleteQ(Queue*queue){
//	if(queue->front==NULL){
//		printf("The queue is Null!\n");
//		return ;
//		//TODO
//	}
	if(queue->front==queue->rear){
		queue->rear=NULL;
		//TODO
	}
	QNode*q=queue->front;
	Point number=q->value;
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

void CountEarlist(int graph[][SIZE],Point points[],Stack * stack,Queue* queue){
	while(!IsEmpty(*queue)){
		Point v=DeleteQ(queue);
		//printf("%d %d\n",v.point,v.earlist);
		Push(stack,v);//为latest做准备 
		for(int j=0;j<SIZE;j++){
			if(graph[v.point][j]!=0){
				//对于每个j，取指向其的点中的最大值 
				if(points[j].earlist<v.earlist+graph[v.point][j]){
					points[j].earlist=v.earlist+graph[v.point][j];					
				}
				graph[v.point][j]=0;
				//拓扑排序，若无入度则入列 
				if(IsHead(graph,j)){
					AddQ(queue,points[j]);
					//TODO
				}
				//TODO
			}
			//TODO
		}
		//TODO
	}
}

void CountLatest(int graph[][SIZE],Point points[],Stack* stack){
	points[((*stack).top)->value.point].latest=((*stack).top)->value.earlist;
	while((*stack).lenth>0){
		Point v=Pop(stack);
		v.latest=points[v.point].latest;
		//printf("%d %d\n",v.point,v.latest);
		for(int i=0;i<SIZE;i++){
			//计算入其的点的latest 
			if(graph[i][v.point]!=0){
				points[i].latest=v.latest-graph[i][v.point];
				//TODO
			}
			//TODO
		}
		//TODO
	}
}

int main(){
	int graph[SIZE][SIZE];
	int graph2[SIZE][SIZE];
	Point points[SIZE];
	for(int i=0;i<SIZE;i++){
		points[i].point=i;
		points[i].earlist=0;
		for(int j=0;j<SIZE;j++){
			scanf("%d",&graph[i][j]);
			graph2[i][j]=graph[i][j];
		}
		//TODO
	}
	
	Queue queue;
	queue.front=NULL;
	queue.rear=NULL;
	Stack stack;
	stack.lenth=0;
	stack.top=NULL;
	for(int i=0;i<SIZE;i++){
		if(IsHead(graph,i)){
			AddQ(&queue,points[i]);
			//TODO
		}
		//TODO
	}
	CountEarlist(graph,points,&stack,&queue);
	CountLatest(graph2,points,&stack);
}
