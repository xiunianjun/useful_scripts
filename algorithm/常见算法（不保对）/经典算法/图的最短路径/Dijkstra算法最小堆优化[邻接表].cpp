#include<stdlib.h>
#include <stdio.h>
#define MAX_SIZE 20
#define INF 10000
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
typedef struct Link{
	Link* next;
	int point;
	int value;
}Link;

Link* CreateLink(){
	Link*p=(Link*)malloc(sizeof(Link));
	p->next=NULL;
	p->point=0;
	p->value=INF;
	return p;
}

void PrintGrapg(Link* link[]){
	for(int i=0;i<8;i++){
		Link*p=link[i];
		while(p){
			printf("%d %d\n",p->point,p->value);
			p=p->next;
			//TODO
		}
		//TODO
	}
}

int main(){
	Link* link[8];//存储邻接表的头节点们 
	for(int i=0;i<8;i++)
		link[i]=NULL;//初始化头指针组
	//输入创建邻接表 
	for(int i=0;i<12;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(link[a-1]==NULL){
			link[a-1]=CreateLink();
			link[a-1]->point=b-1;
			link[a-1]->value=c;
			//TODO
		}
		else{
			Link*p=link[a-1];
			while(p->next){
				p=p->next;
				//TODO
			}
			p->next=CreateLink();
			p->next->point=b-1;
			p->next->value=c;	
		}
	}
	
	
	int visit[8]={0};//标记是否访问，防止打印多次 
	MaxHeap heap=CreateHeapNode();
	Point item;
	item.point=0;
	item.distance=0;
	item.pre=-1;
	visit[0]=1;//先把第一个顶点搞进去 
	Insert(heap,item);
	
	while(heap->size>0){
		Point temp=DeleteVer2(heap);
		if(visit[temp.point]==0){
			printf("%d %d %d\n",temp.point,temp.pre,temp.distance);
			visit[temp.point]=1;
		}
		Link*p=link[temp.point];
		while(p){
			Point a;
			a.point=p->point;
			a.distance=temp.distance+p->value;
			a.pre=temp.point;
			Insert(heap,a);
			p=p->next;
			//TODO
		}
		//TODO
	}
	return 0; 
}
