#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
	int a;
	int e;
	Node*next;
}Node;
typedef Node* Polynomial;


Node* CreateNode(); 
void AddPoly(Polynomial *poly,int a,int e);
Polynomial FindPoly(Polynomial poly,int e);
void OutPutPoly(Polynomial poly);
void InsertPoly(Polynomial poly,int a,int e);

int main() {
	Polynomial firstPoly=NULL;
	Polynomial secondPoly=NULL;
	int a,e;
	
	while(1){
		scanf("%d %d",&a,&e);
		if(a==-1&&e==-1)break;
		AddPoly(&firstPoly,a,e);
	}
	while(1){
		scanf("%d %d",&a,&e);
		if(a==-1&&e==-1)break;
		AddPoly(&secondPoly,a,e);
	}

	Polynomial resultPoly=NULL;
	Polynomial first=firstPoly;
	Polynomial second=secondPoly;
	
	while(first){
		second=secondPoly;
		while(second){
			int finalE=(first->e)+(second->e);
			int finalA=(first->a)*(second->a);
			if(resultPoly==NULL){
				AddPoly(&resultPoly,finalA,finalE);
				second=second->next;
				continue;
				//TODO
			}
			Polynomial finalP=FindPoly(resultPoly,finalE);
			if(finalP==NULL){
				InsertPoly(resultPoly,finalA,finalE);
				//TODO
			}
			else{
				finalP->a+=finalA;
			}
			second=second->next;
			//TODO
		}
		
		first=first->next;
		//TODO
	}
	OutPutPoly(resultPoly);
	return 0;
}
Node* CreateNode(){
	Node*node=(Node*)malloc(sizeof(Node));
	node->a=0;
	node->e=0;
	node->next=NULL;
	return node;
}
void AddPoly(Polynomial *poly,int a,int e){
	Node*node=CreateNode();
	node->a=a;
	node->e=e;
	node->next=NULL;
	if(*poly==NULL){
		*poly=node;
		//TODO
	}else{
		Polynomial p=*poly;
		while(p->next){
			p=p->next;
			//TODO
		}
		p->next=node;
	}
}
Polynomial FindPoly(Polynomial poly,int e){
	Polynomial p=poly;
	while(p&&p->e!=e){
		p=p->next;
		//TODO
	}
	return p;
}
void OutPutPoly(Polynomial poly){
	Polynomial p=poly;
	while(p){
		printf("%+dX^%d",p->a,p->e);
		p=p->next;
		//TODO
	}
}
void InsertPoly(Polynomial poly,int a,int e){
	if(poly==NULL){
		AddPoly(&poly,a,e);
		return;
		//TODO
	}
	Polynomial p=poly;
	while(p->next&&p->next->e>e)
		p=p->next;
	Node*temp=CreateNode();
	temp->a=a;
	temp->e=e;
	temp->next=p->next;
	p->next=temp;
}
