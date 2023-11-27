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

int Count(TreeNode* root)//ÖÐÐò±éÀú¼ÆËã 
{
	int result=0; 
	if(root)
	{
		switch (root->value) {
			case '+':
				result=Count(root->left)+Count(root->right);
				break;
			case '-':
				result=Count(root->left)-Count(root->right);
				break;
			case '*':
				result=Count(root->left)*Count(root->right);
				break;
			case '/':
				result=Count(root->left)/Count(root->right);
				break;
			default:
				result+=root->value-48;
				break;
		}
		
	}
	return result;
}

int main(){
	TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
	CreateTree(&root);
	int result=Count(root);
	printf("%d ",result);
	return 0; 
}
