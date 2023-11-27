#include<stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	TreeNode*left;
	TreeNode*right;
	char value;
}TreeNode;

typedef struct stackNode{
	TreeNode* root;
	stackNode* bottom;
}stackNode; 

typedef stackNode* Stack;

TreeNode* CreateTreeNode(){
	TreeNode*p=(TreeNode*)malloc(sizeof(TreeNode));
	p->value=0;
	p->left=NULL;
	p->right=NULL;
	return p;
}

Stack CreateNode(){
	Stack p=(Stack)malloc(sizeof(stackNode));
	p->bottom=NULL;
	p->root=NULL;
	return p; 
}

void Push(Stack *stack,TreeNode* root){
	Stack node=CreateNode();
	node->root=root;
	if(*stack==NULL){
		*stack=node;
		return;
		//TODO
	}
	node->bottom=*stack;
	*stack=node;
} 

Stack Pop(Stack *stack){
	if(*stack==NULL){
		return NULL;
		//TODO
	}
	Stack p=*stack;
	*stack=(*stack)->bottom;
	return p;
}

TreeNode* CreateTree(){
	Stack stack=NULL;
	TreeNode*p=NULL;
	char value;
	while(1){ 
		scanf("%c",&value);
		if(value=='\n'){
			break;
			//TODO
		}
		p=CreateTreeNode();
		p->value=value;
		if(value>='0'&&value<='9');
		else{
			Stack q1=Pop(&stack);
			Stack q2=Pop(&stack);
			if(q1==NULL||q2==NULL){
				exit(0);
				//TODO
			}
			p->left=q2->root;
			p->right=q1->root;
		}
		Push(&stack,p);
		//TODO
	}
	return stack->root;
}

void InOrder(TreeNode*tree){
	if(tree==NULL){
		return;
		//TODO
	}
	InOrder(tree->left);
	printf("%c",tree->value);
	InOrder(tree->right);
}

int main() {
	TreeNode* tree=CreateTree();
	InOrder(tree);
	return 0;
}
