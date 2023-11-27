#include<stdlib.h>
#include <stdio.h>
typedef struct Link{
	int e;
	int a;
	Link *next;
}Link;

typedef Link* List;

List CreateList(){
	List list=(List)malloc(sizeof(Link));
	list->next=NULL;
	list->e=list->a=0;
	return list;
}

void AddList(List *list,int e,int a){
	(*list)->e=e;
	(*list)->a=a;
	(*list)->next=CreateList();
	(*list)=(*list)->next;
}

void PrintList(List list){
	List p=list;
	printf("%dx^%d",p->a,p->e);
	p=p->next;
	while(p){
		printf("%+dx^%d",p->a,p->e);
		p=p->next;
		//TODO
	}
	printf("\n");
}

void Input(List list){
	char c=' ';
	while(c!='\n'){
		int a,e;
		scanf("%d%*c%*c%d",&a,&e);
		if(c=='-'){
			a=-a;
			
			//TODO
		}
		c=getchar();
		AddList(&list,e,a);
		//TODO
	}
}
void AddTwoList(List head1,List head2){
	List p1=head1;
	List p2=head2;
	while(p1||p2){
		if(p1==NULL){
			while(p2){
				printf("%+dX^%d",p2->a,p2->e);
				p2=p2->next;
				break;
				//TODO
			}
			break;
		}
		else if(p2==NULL){
			while(p1){
				printf("%+dX^%d",p1->a,p1->e);
				p1=p1->next;
				break;
				//TODO
			}
			break;
			//TODO
		}
		if(p1->e>p2->e){
			printf("%+dX^%d",p1->a,p1->e);
			p1=p1->next;
			//TODO
		}
		else if(p1->e<p2->e){
			printf("%+dX^%d",p2->a,p2->e);
			p2=p2->next;
			//TODO
		}
		else if(p1->e==p2->e){
			printf("%+dX^%d",p1->a+p2->a,p1->e);
			p1=p1->next;
			p2=p2->next;
			//TODO
		}
		//TODO
	}
}

void FreeList(List head){
	List p=head;
	while(p->next){
		List temp=p->next;
		p=temp->next;
		free(temp);
		//TODO
	}
	free(p);
}

int main(){
	List list1=CreateList();
	List head1=list1;
	Input(list1);
	List list2=CreateList();
	List head2=list2;
	Input(list2);
	AddTwoList(head1,head2);
	FreeList(head1);
	FreeList(head2);
	return 0; 
}
