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
 
int CountDepth(TreeNode* root)
{
	int HR,HL,MaxH;
	if(!root){
		return 0;
		//TODO
	}
	else if(root)
	{
		HL=CountDepth(root->left);
		HR=CountDepth(root->right);
		MaxH=(HR>HL)?HR :HL;
		return MaxH+1;
	}
}

int main(){
	TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
	CreateTree(&root);
	int result=CountDepth(root);
	printf("%d",result);;
	return 0; 
}
