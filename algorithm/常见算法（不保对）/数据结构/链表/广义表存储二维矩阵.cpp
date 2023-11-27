#include <stdio.h>
#include <stdlib.h>
//term����ֵ 
typedef struct value{
	int row;
	int col;
	int number;
}value;
//ÿ����� 
typedef struct ELNode{
	int tag;//tag=0 head   tag=1 term
	union Difference {
		value termValue;//����term��� 
		ELNode* next;//����ͷ�ڵ� 
	}diff;
	ELNode* right;
	ELNode* low;
}ELNode;


//����һ����� 
ELNode* Create(int row,int col,int number,int tag);
//������� 
void Input(int row,int col,ELNode * head[]);
//������� 
void Print(int row,int col,ELNode* head[]);
//�Ƚϴ�С
int max(int a,int b){return a>b?a:b;}


int main(){
	//�������������У��У����������� 
	int row,col,number;
	scanf("%d %d %d",&row,&col,&number);
	//����ͷָ���鲢��ʼ������ 
	int n=max(row,col);
	ELNode*first=Create(row,col,number,1);
	ELNode* head[n];
	for(int i=0;i<n;i++){
		head[i]=Create(0,0,0,0);
		if(i==0){
			first->right=head[0];
			first->low=head[0];
			//TODO
		}
		else{
			head[i-1]->diff.next=head[i];
		}
	}
	//������� 
	Input(row,col,head);
	//������� 
	Print(row,col,head);
	return 0; 
}

ELNode* Create(int row,int col,int number,int tag){
	ELNode* p=(ELNode*)malloc(sizeof(ELNode));
	p->low=NULL;
	p->right=NULL;
	p->tag=tag;
	//�ж�Ϊͷָ�뻹�ǽ�� 
	if(tag){
		p->diff.termValue.row=row;
		p->diff.termValue.col=col;
		p->diff.termValue.number=number;
		//TODO
	}
	else{
		p->diff.next=NULL;
	}
	return p;
}

void Input(int row,int col,ELNode * head[]){
	ELNode* term=NULL;
	for(int i=0;i<row;i++){
		ELNode*pRow=head[i];
		term=NULL;
		for(int j=0;j<col;j++){
			ELNode*pCol=head[j];
			int a;
			scanf("%d",&a);
			if(a!=0){
				term=Create(i,j,a,1);
				//���½ڵ����ӵ�ԭ������ 
				while(pRow->right){
					pRow=pRow->right;
				}
				pRow->right=term;
				while(pCol->low){
					pCol=pCol->low;
					//TODO
				}
				pCol->low=term;
				//ѭ�� 
				if(i==row-1){
					term->low=head[j];
					//TODO
				}
				//TODO
			}
			//TODO
		}
		//ѭ�� 
		if(term){
			term->right=head[i];
			//TODO
		}
		//TODO
	}
}

void Print(int row,int col,ELNode* head[]){
	for(int i=0;i<row;i++){
		ELNode*p=head[i];
		p=p->right;
		for(int j=0;j<col;j++){
			if(p!=NULL&&p->diff.termValue.col==j){
				printf("%d\t",p->diff.termValue.number);
				p=p->right;
				//TODO
			}
			else{
				printf("0\t");
			}
			//TODO
		}
		printf("\n");
		//TODO
	}
}
