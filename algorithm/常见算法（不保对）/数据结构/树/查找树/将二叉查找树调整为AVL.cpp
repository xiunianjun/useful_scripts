#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 20
typedef struct ADTNode{
	ADTNode* left;
	ADTNode* right;
	int value;
	int height;
}ADTNode;

ADTNode*CreateTreeNode(){
	ADTNode*p=(ADTNode*)malloc(sizeof(ADTNode));
	p->left=NULL;
	p->right=NULL;
	p->value=0;
	return p;
}

void CreateTree(ADTNode** root){
	char c;
	c=getchar();
	if(c==' '){
		*root=NULL;
		//TODO
	}
	else{
		*root=(ADTNode*)malloc(sizeof(ADTNode));
		if(*root==NULL){
			exit(1); 
			//TODO
		}
		(*root)->value=c-48;
		CreateTree(&((*root)->left));
		CreateTree(&((*root)->right));
	}
}

int max(int a,int b){
	return a>b?a:b;
}

int Height(ADTNode* root){
	if(root==NULL){
		return 0;
		//TODO
	}
	return max(Height(root->left),Height(root->right))+1;
}

ADTNode* YouXuan(ADTNode* node){
	ADTNode*temp=node->left;
	node->left=temp->right;
	temp->right=node;
	return temp;
}
ADTNode* ZuoXuan(ADTNode* node){
	ADTNode*temp=node->right;
	node->right=temp->left;
	temp->left=node;
	return temp;
}
ADTNode* LR(ADTNode* node){
	node->left=ZuoXuan(node->left);//×ó±ßÏÈ×óÐý 
	node=YouXuan(node);//ÓÒ±ßÔÙÓÒÐý 
	return node;
}
ADTNode* RL(ADTNode* node){
	node->right=YouXuan(node->right);//ÓÒ±ßÏÈÓÒÐý 
	node=ZuoXuan(node);//×ó±ßÔÙ×óÐý 
	return node;
}

ADTNode* AdjustTree(ADTNode* tree){
	if(fabs(Height(tree->left)-Height(tree->right))<=1){
		return tree;
		//TODO
	}
	else if(Height(tree->left)>Height(tree->right)){
		if(Height(tree->left->left)>=Height(tree->left->right)){
			tree=YouXuan(tree);
			//TODO
		}
		else{
			tree=LR(tree);
			//TODO
		}
		//TODO
	}
	else{
		if(Height(tree->right->right)>=Height(tree->right->left)){
			tree=ZuoXuan(tree);
			//TODO
		}
		else{
			tree=RL(tree);
			//TODO
		}		
	}
	tree->left=AdjustTree(tree->left);
	tree->right=AdjustTree(tree->right);
	while(fabs(Height(tree->left)-Height(tree->right))>1){
		tree=AdjustTree(tree);
	}
	return tree;
}
void PreOrder(ADTNode*tree){
	if(tree==NULL){
		printf(" ");
		return;
		//TODO
	}
	printf("%d",tree->value);
	PreOrder(tree->left);
	PreOrder(tree->right);
} 
int main(){
	ADTNode*tree=NULL;
	CreateTree(&tree);
	int result=Height(tree);
	printf("%d\n",result);
	tree=AdjustTree(tree);
	PreOrder(tree);
}
