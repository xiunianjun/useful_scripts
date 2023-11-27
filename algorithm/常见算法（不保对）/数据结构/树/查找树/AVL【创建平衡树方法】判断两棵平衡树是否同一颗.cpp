#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int value;
	TreeNode* left;
	TreeNode* right;
	int flag;
}TreeNode;

TreeNode* CreateTreeNode(){
	TreeNode*p=(TreeNode*)malloc(sizeof(TreeNode));
	p->value=0;
	p->left=NULL;
	p->right=NULL;
	p->flag=0;
	return p;
} 

TreeNode* Insert(TreeNode*tree,TreeNode*node){
	if(tree==NULL){
		return node;
		//TODO
	}
	else{
		if(tree->value>node->value){
			tree->left=Insert(tree->left,node);
			//TODO
		}
		else{
			tree->right=Insert(tree->right,node);
		}
		return tree;
	}
}

TreeNode* Create(int a[],int n){
	TreeNode*tree=NULL;
	for(int i=0;i<n;i++){
		TreeNode*p=CreateTreeNode();
		p->value=a[i];
		tree=Insert(tree,p);
		//TODO
	}
	return tree;
}

int IsATree(int a[],int n,TreeNode*tree){
	for(int i=0;i<n;i++){
		TreeNode*p=tree;
		while(p){
			if(p->value==a[i]){
				p->flag=1;
				break;
				//TODO
			}
			if(p->flag==0){
				return 0; 
				//TODO
			}
			if(p->value>a[i]){
				p=p->left;
				//TODO
			}
			else if(p->value<a[i]){
				p=p->right;
				//TODO
			}
			//TODO
		}
		//TODO
	}
	return 1;
}

int main(){
	int n=4;
	int a[]={3,1,2,4};
	int b[]={3,2,4,1};
	TreeNode*tree=Create(a,n);
	printf("%d",IsATree(b,n,tree));
	return 0;
}
