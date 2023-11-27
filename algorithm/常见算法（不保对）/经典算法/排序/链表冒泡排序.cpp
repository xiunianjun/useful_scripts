#include <stdio.h>
#include <stdlib.h> 

typedef struct Link{
	int value;
	Link *next;
}Link;

typedef Link* List;

List CreateList(){
	List list=(List)malloc(sizeof(Link));
	list->next=NULL;
	list->value=0;
	return list;
}

void AddList(List *list,int value){
	List p=CreateList();
	p->value=value;
	if(*list==NULL){
		*list=p;
		return;
		//TODO
	}
	List q=*list;
	while(q->next){
		q=q->next;
		//TODO
	}
	q->next=p;
}

void PrintList(List list){
	List p=list;
	printf("%d",p->value);
	p=p->next;
	while(p){
		printf("%d",p->value);
		p=p->next;
		//TODO
	}
	printf("\n");
}

void BubbleSort(List head){
	//�ҵ������Ǹ�ָ�� 
	List last=head;
	while(last->next){
		last=last->next;
		//TODO
	}
	
	
	List p=last;
	//��־�����Ƿ���� 
	int flag=1;
	while(flag){
		flag=0;
		//ÿ�ִ��㿪ʼ 
		List q=head;
		while(q!=p){
			//ð�ݽ��� 
			if(q->next->value<q->value){
				int temp=q->value;
				q->value=q->next->value;
				q->next->value=temp;
				flag=1; 
				//TODO
			}
			q=q->next;
			//TODO
		}
		//ĩλlastǰ�ơ�������j<n-i-1�� 
		p=q;
		//TODO
	}
	PrintList(head);
}

int main(){
	List list=NULL;
	int a[8]={8,7,3,5,4,2,6,1};
	for(int i=0;i<8;i++){
		AddList(&list,a[i]);
	}
	PrintList(list);
	BubbleSort(list);
}


