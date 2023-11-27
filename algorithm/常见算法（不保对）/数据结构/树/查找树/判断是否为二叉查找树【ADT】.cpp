#include <stdio.h>
#include <stdlib.h>
#define INF 1000
typedef struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int value;
}TreeNode;

void CreateTree(TreeNode** root);
//法一：中序递归 
int isADT(TreeNode* root,TreeNode* last){
    if(root == NULL)    
        return 1;
    if(!isADT(root->left,last))    
        return 0;
    if(last!=NULL&&root->value <= last->value)    
        return 0;
    last=root;
    if(!isADT(root->right,last))    
        return 0;
    return 1;
}
//法二：范围递归
int IsADT(TreeNode*root,int minVal,int maxVal){
	if(root==NULL)
		return 1;
	if(root->value>=maxVal||root->value<=minVal)
		return 0;
	if(!IsADT(root->left,minVal,root->value))
		return 0;
	if(!IsADT(root->right,root->value,maxVal))
		return 0;
	return 1;
}
//法三：中序遍历所得数组递增
//public class Solution {
//    public bool IsValidBST(TreeNode root) {
//        List<int> a=new List<int>();
//        InOrder(a,root);
//        for(int i=1;i<a.Count;i++){
//            if(a[i]<=a[i-1]) return false;
//        }
//        return true;
//    }
//    public void InOrder(List<int> a,TreeNode root){
//        if(root==null)
//            return;
//        InOrder(a,root.left);
//        a.Add(root.val);
//        InOrder(a,root.right);
//    }
//} 
int main() {
	TreeNode* tree=NULL;
	CreateTree(&tree);
	int result=IsADT(tree,-INF,INF);
	printf("%d",result);
	return 0;
}
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
