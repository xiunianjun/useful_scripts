#include <stdio.h>
#include <stdlib.h>
//term结点的值 
typedef struct value{
	int row;
	int col;
	int number;
}value;
//每个结点 
typedef struct ELNode{
	int tag;//tag=0 head   tag=1 term
	union Difference {
		value termValue;//对于term结点 
		ELNode* next;//对于头节点 
	}diff;
	ELNode* right;
	ELNode* low;
}ELNode;


//创造一个结点 
ELNode* Create(int row,int col,int number,int tag);
//输入矩阵 
void Input(int row,int col,ELNode * head[]);
//输出矩阵 
void Print(int row,int col,ELNode* head[]);
//比较大小
int max(int a,int b){return a>b?a:b;}


int main(){
	//输入矩阵参数：行，列，非零数字数 
	int row,col,number;
	scanf("%d %d %d",&row,&col,&number);
	//创建头指针组并初始化连接 
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
	//输入矩阵 
	Input(row,col,head);
	//输出矩阵 
	Print(row,col,head);
	return 0; 
}

ELNode* Create(int row,int col,int number,int tag){
	ELNode* p=(ELNode*)malloc(sizeof(ELNode));
	p->low=NULL;
	p->right=NULL;
	p->tag=tag;
	//判断为头指针还是结点 
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
				//把新节点连接到原来表中 
				while(pRow->right){
					pRow=pRow->right;
				}
				pRow->right=term;
				while(pCol->low){
					pCol=pCol->low;
					//TODO
				}
				pCol->low=term;
				//循环 
				if(i==row-1){
					term->low=head[j];
					//TODO
				}
				//TODO
			}
			//TODO
		}
		//循环 
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
