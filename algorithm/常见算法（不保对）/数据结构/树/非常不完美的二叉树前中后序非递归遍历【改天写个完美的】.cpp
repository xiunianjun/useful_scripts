#include<stdlib.h>
#include <stdio.h>

typedef struct TreeNode{
	TreeNode*left;
	TreeNode*right;
	int value;
}TreeNode;

typedef struct Node{
	Node*bottom;
	TreeNode* node;
}Node;

typedef struct Stack{
	Node*top;
	int lenth;
}Stack;

TreeNode* CreateTreeNode(){
	TreeNode*p=(TreeNode*)malloc(sizeof(TreeNode));
	p->value=0;
	p->left=NULL;
	p->right=NULL;
	return p;
}

Node* CreateNode(){
	Node*p=(Node*)malloc(sizeof(Node));
	p->node=NULL;
	p->bottom=NULL;
	return p;
}

void Push(Stack *stack,TreeNode* tree){
	Node *p=CreateNode();
	p->node=tree;
	p->bottom=(*stack).top;
	(*stack).lenth++;
	(*stack).top=p;
}

TreeNode* Pop(Stack* stack){
	TreeNode* number=(*stack).top->node;
	(*stack).top=(*stack).top->bottom;
	(*stack).lenth--;
	return number;
}

//前序遍历 
void PreOrder(TreeNode* tree){
	Stack stack;
	stack.top=NULL;
	TreeNode*p=tree;
	int flag=0;
	while(p){ 
		if(!flag){
			while(p->left){
				Push(&stack,p);
				printf("%d ",p->value);
				p=p->left;
				//TODO
			}
			printf("%d ",p->value);
		}
		if(p->right!=NULL){
			flag=0;
			p=p->right;
			//TODO
		}
		else{
			flag=1;
			if(stack.lenth==0){
				p=NULL;
				//TODO
			}
			else
				p=Pop(&stack);
		}
	}
}
//中序遍历 
void InOrder(TreeNode* tree){
	Stack stack;
	stack.lenth=0;
	stack.top=NULL;
	TreeNode*p=tree;
	int flag=0;
	while(p){
		while(p->left&&!flag){
			Push(&stack,p);
			p=p->left;
			//TODO
		}
		printf("%d ",p->value);
		if(p->right!=NULL){
			flag=0;
			p=p->right;
			//TODO
		}
		else{
			flag=1;
			if(stack.lenth==0){
				p=NULL;
				//TODO
			}
			else
				p=Pop(&stack);
		}
	}
}

//后序遍历  
void PostOrder(TreeNode* tree){
	Stack stack;
	stack.top=NULL;
	stack.lenth=0;
	TreeNode*p=tree;
	//左右树均被遍历 
	int flag=0;
	int flag2=0;
	while(p){ 
		if(!flag){
			if(!p->left&&p){
				Push(&stack,p);
				//TODO
			}
			if(p->left){
				while(p->left){
					Push(&stack,p);
					p=p->left;
				}
				if(p->right!=NULL){
					Push(&stack,p);
					p=p->right;
					flag=0;
					continue;
					//TODO
				}
				printf("%d ",p->value);
				p=(stack.top)->node;
				flag=1;
				continue;
				//TODO
			}	
		} 
		if(p->right!=NULL&&!flag2){
			flag=0;
			p=p->right;
			//TODO
		}
		else{
			flag=1;
			flag2=1;
			if(stack.lenth==0){
				p=NULL;
				//TODO
			}
			else{
				p=Pop(&stack);
				int c=p->value;
				printf("%d ",c);
				if(stack.lenth==1){
					if(c==(stack.top)->node->left->value){
						p=(stack.top)->node;
						flag2=0;//TODO
					}
					else{
						p=(stack.top)->node;
						printf("%d ",p->value);
						return;
					}
					//TODO
				}
			}
		}
	}
}

void CreateTree(TreeNode** root){
	char c;
	c=getchar();
	if(c==' '){
		*root=NULL;
		//TODO
	}
	else{
		*root=CreateTreeNode();
		if(*root==NULL){
			exit(1); 
			//TODO
		}
		(*root)->value=c-48;
		CreateTree(&((*root)->left));
		CreateTree(&((*root)->right));
	}
}

int main(){
	TreeNode* tree=(TreeNode*)malloc(sizeof(TreeNode));
	CreateTree(&tree);
	PostOrder(tree);
	return 0; 
}
