#include<stdlib.h>
#include <stdio.h>
#define MAX_SIZE 20
#define INF 10000
#define SIZE 8

typedef struct Point{
	int pointBegin;
	int pointEnd;
	int value; 
}Point;
typedef struct{
	Point value;
	int parent;
}SetType;
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
	p->array[0].value=-INF;
	p->array[0].pointBegin=-1;
	for(int i=0;i<p->capacity+1;i++){
		p->array[i].pointEnd=i;
		//TODO
	}
	return p;
}

void Insert(MaxHeap heap,Point item){
	int i=++(heap->size);
	while(heap->array[i/2].value>item.value){
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
		if(child!=heap->size&&heap->array[child].value>heap->array[child+1].value){
			child++;
			//TODO
		}
		if(temp.value<heap->array[child].value){
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

MaxHeap CreateHeap(int n){
	MaxHeap heap=CreateHeapNode();
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&(heap->array[i].pointBegin),&(heap->array[i].pointEnd),&(heap->array[i].value));
		heap->size++;
		//TODO
	}
	for(int i=heap->size/2;i>=1;i--){
		if(2*i>heap->size){
			i--;
			//TODO
		}
		AdjustToHeap(heap,i);
		//TODO
	}
	return heap;
}

int FindParent(SetType array[],int index){
	if(array[index].parent<0){
		return index;
		//TODO
	}
	else{
		return array[index].parent=FindParent(array,array[index].parent);
	}
} 

void Union(SetType array[],int n,int rootOne,int rootTwo){
	if(rootOne!=rootTwo){
		if(array[rootOne].parent<array[rootTwo].parent){
			array[rootOne].parent+=array[rootTwo].parent;
			array[rootTwo].parent=rootOne;
			//TODO
		}
		else{
			array[rootTwo].parent+=array[rootOne].parent;
			array[rootOne].parent=rootTwo;
		}
	}
}

int main(){
	MaxHeap heap=CreateHeap(12);
	SetType bing[8];
	for(int i=0;i<8;i++){
		bing[i].parent=-1;
		//TODO
	}
	int index=0;
	while(index<7){
		Point temp=DeleteVer2(heap);
		int parent1=FindParent(bing,temp.pointBegin-1);
		int parent2=FindParent(bing,temp.pointEnd-1);
		if(parent1!=parent2||parent1==-1){
			bing[index].value=temp;
			Union(bing,8,parent1,parent2);
			index++;
			//TODO
		}
		//TODO
	}
	for(int i=0;i<8;i++){
		printf("%d %d %d %d\n",bing[i].parent,bing[i].value.pointBegin,bing[i].value.pointEnd,bing[i].value.value);
		//TODO
	}
}
