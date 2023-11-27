#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
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

void ToArray(TreeNode* tree,int a[],int *count){
	if(tree==NULL){
		return;
		//TODO
	}
	ToArray(tree->left,a,count);
	a[(*count)++]=tree->value;
	ToArray(tree->right,a,count);
} 

int IsADT(TreeNode* tree,int a[]){
	int count=0;
	ToArray(tree,a,&count);
	for(int i=1;i<count;i++){
		if(a[i-1]>a[i]){
			return 0;
			//TODO
		}
		//TODO
	}
	return 1;
}

int main() {
	TreeNode* tree=NULL;
	CreateTree(&tree);
	int a[MAX_SIZE]={0};
	int result=IsADT(tree,a);
	printf("%d",result);
	return 0;
}
