#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	char value;
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
		(*root)->value=c;
		CreateTree(&((*root)->left));
		CreateTree(&((*root)->right));
	}
}

void PrintExpreession(TreeNode* root){
	if(root->left!=NULL){
		if(root->left->left!=NULL){
			printf("(");
			//TODO
		}
		PrintExpreession(root->left);
		if(root->left->left!=NULL){
			printf(")");
			//TODO
		}
		
	}
	printf("%c ",root->value);
	if(root->right!=NULL){
		PrintExpreession(root->right);
		//TODO
	}
}

int main(){
	TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
	CreateTree(&root);
	PrintExpreession(root);
	return 0; 
}
