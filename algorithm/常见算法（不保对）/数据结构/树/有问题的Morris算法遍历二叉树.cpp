#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int value;
}TreeNode;

void CreateTree(TreeNode** root){
	char c;
	c=getchar();
	if(c==' '){
		*root=NULL;
		//TODO
	}
	else{
		*root=(TreeNode*)malloc(sizeof(TreeNode));
		if(*root==NULL){
			exit(1); 
			//TODO
		}
		(*root)->value=c-48;
		CreateTree(&((*root)->left));
		CreateTree(&((*root)->right));
	}
}

TreeNode* PreParent(TreeNode* target){
	TreeNode*p=target;
	if(p->left==NULL){
		return p;
		//TODO
	}
	p=p->left;
	while(p->right){
		p=p->right;
		//TODO
	}
	return p;
}

void MorrisTravel(TreeNode*tree){
	if(tree==NULL){
		return;
		//TODO
	}
	if(tree->left==NULL){
		printf("%d",tree->value);
		MorrisTravel(tree->right);
		//TODO
	}
	else{
		TreeNode*p=PreParent(tree);
		if(p->right==NULL){
			p->right=tree;
			MorrisTravel(tree->left);
		}
		else{
			if(p->right==tree){
				p->right=NULL;
				printf("%d",tree->value);
			}
			MorrisTravel(p->right);
		}
		
		
	}
} 

int main() {
	TreeNode* tree=NULL;
	CreateTree(&tree);
	MorrisTravel(tree);
	return 0;
}
