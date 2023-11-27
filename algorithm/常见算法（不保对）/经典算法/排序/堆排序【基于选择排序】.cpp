#include <stdio.h>
#include <stdlib.h> 
typedef struct HeapStruct{
	int* array;
	int size;
}HeapStruct;
typedef HeapStruct* MaxHeap;

void AdjustToHeap(MaxHeap heap,int parent,int n){
	int child;
	int temp=heap->array[parent];
	for(;parent*2+1<n;parent=child){
		child=parent*2+1;
		if(child!=n-1&&heap->array[child]<heap->array[child+1]){
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

void Output(int a[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
		//TODO
	}
}

void HeapSort(int *a,int n){
	MaxHeap heap=(MaxHeap)malloc(sizeof(HeapStruct));
	heap->array=a;
	heap->size=n;
	for(int i=(heap->size-1)/2;i>=0;i--){
		if(2*i>heap->size-1){
			i--;
			//TODO
		}
		AdjustToHeap(heap,i,heap->size);
		//TODO
	}
	for(int i=heap->size-1;i>0;i--){
		int temp=heap->array[0];
		heap->array[0]=heap->array[i];
		heap->array[i]=temp;
		AdjustToHeap(heap,0,i);
		//TODO
	}
	
}

int main(){
	int a[8]={8,1,5,2,7,6,3,4};
	HeapSort(a,8);
	Output(a,8);
} 
