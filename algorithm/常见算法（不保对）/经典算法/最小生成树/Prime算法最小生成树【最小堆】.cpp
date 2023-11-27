#include<stdlib.h>
#include <stdio.h>
#define MAX_SIZE 20
#define INF 10000
#define SIZE 8
typedef struct Point{
	int point;
	int pre;
	int distance; 
}Point;
typedef struct HeapStruct{
	Point* array;
	int size;
	int capacity;
}HeapStruct;
typedef HeapStruct* MaxHeap;

MaxHeap CreateHeapNode(){
	MaxHeap p=(MaxHeap)malloc(sizeof(HeapStruct));
	p->capacity=MAX_SIZE;
	p->array=(Point*)malloc(sizeof(Point)*(p->capacity+1));
	p->size=0;
	p->array[0].distance=-INF;
	p->array[0].pre=-1;
	for(int i=0;i<p->capacity+1;i++){
		p->array[i].point=i;
		//TODO
	}
	return p;
}

void Insert(MaxHeap heap,Point item){
	int i=++(heap->size);
	while(heap->array[i/2].distance>item.distance){
		heap->array[i]=heap->array[i/2];
		i/=2;
	}
	heap->array[i]=item;
}

void AdjustToHeap(MaxHeap heap,int parent){
	int child;
	Point temp=heap->array[parent];
	for(;parent*2<=heap->size;parent=child){
		child=parent*2;
		if(child!=heap->size&&heap->array[child].distance>heap->array[child+1].distance){
			child++;
			//TODO
		}
		if(temp.distance<heap->array[child].distance){
			break;
			//TODO
		}
		else{
			heap->array[parent]=heap->array[child];
		}
		//TODO
	}
	heap->array[parent]=temp;
}

Point DeleteVer2(MaxHeap heap){
	Point minEle=heap->array[1];
	heap->array[1]=heap->array[(heap->size)--];
	AdjustToHeap(heap,1);
	return minEle;
}

int main(){
	int graph[SIZE][SIZE];
	//ÊäÈëÁÚ½Ó¾ØÕó 
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			scanf("%d",&graph[i][j]);
			if(graph[i][j]==0){
				graph[i][j]=INF;
				//TODO
			}
			//TODO
		}
		//TODO
	}
	
	
	int visit[SIZE]={0};
	Point tree[SIZE];
	int index=0;
	MaxHeap heap=CreateHeapNode();
	Point point;
	point.distance=0;
	point.point=0;
	point.pre=-1;
	Insert(heap,point);
	
	while(index<=7){
		Point temp=DeleteVer2(heap);
		if(visit[temp.point]==1){
			continue;
		}
		tree[index]=temp;
		visit[temp.point]=1;
		for(int i=0;i<SIZE;i++){
			if(graph[temp.point][i]!=INF&&visit[i]!=1){
				Point p;
				p.distance=graph[temp.point][i];
				p.point=i;
				p.pre=temp.point;
				Insert(heap,p);
				//TODO
			}
			//TODO
		}
		index++;
	}
	
	
	for(int i=0;i<SIZE;i++){
		printf("%d %d %d\n",tree[i].pre,tree[i].point,tree[i].distance);
		//TODO
	}
	return 0;
}
