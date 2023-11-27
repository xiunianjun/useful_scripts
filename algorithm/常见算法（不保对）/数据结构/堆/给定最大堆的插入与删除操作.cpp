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

MaxHeap CreateHeap(){
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

//思路更加清晰的标答 
int DeleteVer2(MaxHeap heap){
	int parent=1,child=2;
	int maxEle=heap->array[1];
	int temp=heap->array[(heap->size)--];
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
	return maxEle;
}

void OutPut(int a[],int n){
	for(int i=0;i<=n;i++){
		printf("%d ",a[i]);
		//TODO
	}
	printf("\n");
}

int main(){
	MaxHeap heap=CreateHeap();
	int a[MAX_SIZE]={INF,10,8,5,6,3,4};
	heap->array= a;
	heap->size=6;
	OutPut(heap->array,heap->size);
	Insert(heap,7);
	OutPut(heap->array,heap->size);
	int result=DeleteVer2(heap);
	OutPut(heap->array,heap->size);
	printf("%d",result);
	return 0;
}
