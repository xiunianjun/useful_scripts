#include<stdio.h>
#define MAX_NUMBER 8
#include<stdlib.h>

typedef struct Link{
	int data;
	Link *next;
};
typedef Link*  List;

List MakeList(){
	List list=(List)malloc(sizeof(struct Link));
	list->next=NULL;
	list->data=0;
	return list;
}

void AddData(List *list,int n){
	(*list)->data=n;
	(*list)->next=MakeList();
	(*list)=(*list)->next;
}

void OutputData(List head){
	List p=head;
	printf("%p\n",p);
	while(p){
		printf("%d\t",p->data);
		p=p->next;
		printf("%p\n",p);
		//TODO
	}
}

int Lenth(List head){
	int lenth=0;
	List p=head;
	while(p!=NULL){
		p=p->next;
		lenth++;
	}
	return lenth;
}

List Find(List head,int find){
	List p=head;
	while(p!=NULL){
		if(p->data==find){
			return p;
			//TODO
		}
		p=p->next;
	}
	return NULL;
}

void InsertANumber(List head,int data){
	List p=head;
	for(int i=0;p->next!=NULL&&p->next->data<data;i++){
		p=p->next;
		//TODO
	}
	List newList=MakeList();
	newList->data=data;
	newList->next=p->next;
	p->next=newList;
}

void DeleteANumber(List head,int number){
	List p=head;
	while(p!=NULL){
		if(p->next->data==number){
			break;
			//TODO
		}
		p=p->next;
		//TODO
	}
	
	p->next=p->next->next;
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
	List list=MakeList();
	List head=list;
	while(1){
		printf("Input 1 to add to list,2 to get the lenth of the list,3 to find an element,4 to insert a number,5 to delete,6 to output all.\n");
		int choice;
		scanf("%d",&choice);
		switch (choice) {
			case 1:
				for(int i=0;i<5;i++){
					AddData(&list,i);
					//TODO
				}
				break;
			case 2:
				printf("The lenth of the list is %d\n",Lenth(head));
				//TODO
				break;
			case 3:
			{
				printf("Please input the key number.\n");
				int number;
				scanf("%d",&number);
				List out=Find(head,number);
				if(out!=NULL){
					printf("The number is%d\n",out->data);
					//TODO
				}
				else {
					printf("No finding!\n");
				}
				break;
			}
			case 4:
			{
				printf("Please input the key number you want to insert.\n");
				int number;
				scanf("%d",&number);
				InsertANumber(head,number);
				OutputData(head);
				break; 
			}
			case 5:
			{
				printf("Please input the key number you want to delete.\n");
				int number;
				scanf("%d",&number);
				DeleteANumber(head,number);
				OutputData(head);
			}
			case 6:
				OutputData(head);
				break;
			default:
				//TODO
				break;
		}
		//TODO
	}
	FreeList(head);
	return 0;
}
