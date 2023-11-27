#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define INF 10000
typedef struct HeapStruct{
	int* array;
	int size;
	int capacity;
}HeapStruct;
typedef HeapStruct* MaxHeap;

MaxHeap CreateHeapNode(){
	MaxHeap p=(MaxHeap)malloc(sizeof(HeapStruct));
	p->capacity=MAX_SIZE;
	p->array=(int*)malloc(sizeof(int)*(p->capacity+1));
	p->size=0;
	p->array[0]=INF;
	return p;
}

void Insert(MaxHeap heap,int item){
	int i=++(heap->size);
	while(heap->array[i/2]<item){
		heap->array[i]=heap->array[i/2];
		i/=2;
	}
	heap->array[i]=item;
}

void AdjustToHeap(MaxHeap heap,int parent){
	int child;
	int temp=heap->array[parent];
	for(;parent*2<=heap->size;parent=child){
		child=parent*2;
		if(child!=heap->size&&heap->array[child]<heap->array[child+1]){
			child++;
			//TODO
		}
		if(temp>heap->array[child]){
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

int DeleteVer2(MaxHeap heap){
	int maxEle=heap->array[1];
	heap->array[1]=heap->array[(heap->size)--];
	AdjustToHeap(heap,1);
	return maxEle;
}

void OutPut(int a[],int n){
	for(int i=0;i<=n;i++){
		printf("%d ",a[i]);
		//TODO
	}
	printf("\n");
}

MaxHeap CreateHeap(int a[],int n){
	MaxHeap heap=CreateHeapNode();
	for(int i=1;i<=n;i++){
		heap->array[i]=a[i];
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

int main(){
	int a[MAX_SIZE]={INF,3,4,5,6,8,10};
	//法一：逐个插入，复杂度O（NlogN） 
//	for(int i=1;i<=6;i++){
//		Insert(heap,a[i]);
//		//TODO
//	}
//	OutPut(heap->array,heap->size);
	//法二
	MaxHeap heap=CreateHeap(a,6);
	OutPut(heap->array,6);
	return 0;
}
