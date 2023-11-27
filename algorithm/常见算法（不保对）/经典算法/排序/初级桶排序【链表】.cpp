#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	int count;
	Node*next;
}Node;

typedef Node* List;

Node* CreateNode(){
	Node*node=(Node*)malloc(sizeof(Node));
	node->value=0;
	node->count=0;
	node->next=NULL;
	return node;
}

void AddList(List *list,int value){
	Node*node=CreateNode();
	node->value=value;
	node->count=0;
	node->next=NULL;
	if(*list==NULL){
		*list=node;
		//TODO
	}else{
		List p=*list;
		while(p->next){
			p=p->next;
			//TODO
		}
		p->next=node;
	}
}

//void OutPutList(List list){
//	List p=list;
//	while(p){
//		printf("%d\n",p->value);
//		p=p->next;
//		//TODO
//	}
//}

void InsertList(List *list,int value){
	if(*list==NULL){
		AddList(list,value);
		(*list)->count++;
		return;
		//TODO
	}
	List p=*list;
	while(p->next&&p->next->value>value)
		p=p->next;
	Node*temp=CreateNode();
	temp->value=value;
	temp->count=1;
	if(p==*list){
		temp->next=*list;
		*list=temp;
		//TODO
	}
	else{
		temp->next=p->next;
		p->next=temp;
	}
}

List Find(List list,int value){
	if(list==NULL){
		return NULL;
		//TODO
	}
	List p=list;
	while(p&&p->value!=value){
		p=p->next;
		//TODO
	}
	return p;
}

int main() {
	List list=NULL;
	int c=0;
	while(1){
		scanf("%d",&c);
		if(c==-1)break;
		List p=Find(list,c);
		if(p!=NULL){
			p->count++;
			//TODO
		}
		else{
			InsertList(&list,c); 
		} 
		//TODO
	}
	List p=list;
	while(p){
		while(p->count>0){
			printf("%d\n",p->value);
			p->count--;
			//TODO
		}
		p=p->next;
		//TODO
	}
	return 0;
}
