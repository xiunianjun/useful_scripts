#include<stdlib.h>
#include <stdio.h>

typedef struct TreeNode{
	TreeNode*left;
	TreeNode*right;
	int value;
	int tag;
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
	p->tag=0;
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

void PreOrder(TreeNode* tree){
	Stack stack;
	stack.lenth=0;
	stack.top=NULL;
	TreeNode*p=tree;
	while(p||stack.lenth){
		while(p){
			Push(&stack,p);
			printf("%d ",p->value);
			p=p->left;
			//TODO
		}
		if(stack.lenth){
			p=Pop(&stack);
			p=p->right;
			//TODO
		}
	}
}

void InOrder(TreeNode* tree){
	Stack stack;
	stack.lenth=0;
	stack.top=NULL;
	TreeNode*p=tree;
	while(p||stack.lenth){
		while(p){
			Push(&stack,p);
			p=p->left;
			//TODO
		}
		if(stack.lenth){
			p=Pop(&stack);
			printf("%d ",p->value);
			p=p->right;
			//TODO
		}
	}
}

void PostOrder(TreeNode* tree){
	Stack stack;
	stack.lenth=0;
	stack.top=NULL;
	TreeNode*p=tree;
	while(1){
		while(p&&!p->tag){
			p->tag=1;
			Push(&stack,p);
			p=p->left;
			//TODO
		}
		if(stack.lenth){
			p=Pop(&stack);
			if(p->tag==1){
				p->tag++;
				Push(&stack,p);
				p=p->right; 
			}
			else if(p->tag==2){
				printf("%d ",p->value);
				if(!stack.lenth){
					break;
					//TODO
				}
				//TODO
			}
		}
	}
}
//»òÕß£º
//void PostOrder(TreeNode* tree){
//	Stack stack;
//	stack.lenth=0;
//	stack.top=NULL;
//	TreeNode*p=tree;
//	while(p||stack.lenth){
//		while(p){
//			p->tag=1;
//			Push(&stack,p);
//			p=p->left;
//			//TODO
//		}
//		if(stack.lenth){
//			p=Pop(&stack);
//			if(p->tag==1){
//				p->tag++;
//				Push(&stack,p);
//				p=p->right; 
//			}
//			else if(p->tag==2){
//				printf("%d ",p->value);
//				p=NULL;
//				//TODO
//			}
//		}
//	}
//} 

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
	//PreOrder(tree);
//	InOrder(tree);
	PostOrder(tree);
	return 0; 
}
