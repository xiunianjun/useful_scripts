#include <stdio.h>
#include <stack>
#include <stdlib.h>
using namespace std;
typedef struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int value;
}TreeNode;
//创建树 
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
//中序遍历 
void InOrder(TreeNode* root)
{
	if(root)
	{
		InOrder(root->left);
		printf("%d ",root->value);
		InOrder(root->right);
	}
}
//先序遍历 
void PreOrder(TreeNode* root) 
{
	if(root)
	{
		printf("%c ",root->value);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}


//后序遍历
void PostOrder(TreeNode* root)
{
	if(root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%c ",root->value);
	}
}
//搜索在范围内的树并求和 
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

void inTraversal(TreeNode* root){
	stack<TreeNode*> s;
	TreeNode* p=root;
	do{
		while(p){
			s.push(p);
			p=p->left;
		}
		p=s.top();
		s.pop();
		printf("%d ",p->value);
		p=p->right;
	}while(!s.empty()||p);
}

int main(){
	TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
	CreateTree(&root);
	InOrder(root);
	printf("\n");
	inTraversal(root);
//	PostOrder(root);
//	printf("\n");
//	PostOrder(root);
//	printf("\n");
	//printf("%d\n",Solution(root,2,1));
	return 0; 
}
