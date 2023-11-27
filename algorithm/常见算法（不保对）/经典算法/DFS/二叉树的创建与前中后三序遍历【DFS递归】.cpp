#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int value;
}TreeNode;
//������ 
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
//������� 
void InOrder(TreeNode* root)
{
	if(root)
	{
		printf("%c ",root->value);
		InOrder(root->left);
		InOrder(root->right);
	}
}
//������� 
void PreOrder(TreeNode* root) 
{
	if(root)
	{
		printf("%c ",root->value);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}


//�������
void PostOrder(TreeNode* root)
{
	if(root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%c ",root->value);
	}
}
//�����ڷ�Χ�ڵ�������� 
int Solution(TreeNode* root,int max,int min){
	if(root==NULL){
		return 0;
		//TODO
	}
	if(root->value>max){
		return Solution(root->left,max,min);
		//TODO
	}
	if(root->value<min){
		return Solution(root->right,max,min);
		//TODO
	}
	return root->value+Solution(root->left,max,min)+Solution(root->right,max,min);
}

int main(){
	TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
	CreateTree(&root);
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	printf("%d\n",Solution(root,2,1));
	return 0; 
}
