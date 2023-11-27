#include <stdio.h>
#include<stdlib.h>
//建立树结点 
typedef struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int value;
}TreeNode;
//建立链表结点 
typedef struct Link{
	TreeNode* data;
	Link *next;
}Link;
typedef Link*  List;

//创造树结点的函数，参数为该树节点的权值 
TreeNode* CreateTreeNode(int value){
	TreeNode*q=(TreeNode*)malloc(sizeof(TreeNode));
	q->value=value;
	q->left=NULL;
	q->right=NULL;
	return q;
}
//创建链表结点的函数，返回一个值为空的链表结点 
List MakeList(){
	List list=(List)malloc(sizeof(struct Link));
	list->next=NULL;
	list->data=NULL;
	return list;
}
//向链表的末尾添加新的树结点 
void AddData(List *list,TreeNode* n){
	(*list)->data=n;
	(*list)->next=MakeList();
	(*list)=(*list)->next;
}
//将特定权值的树插入链表的某个位置 
void InsertANumber(List head,TreeNode* data){
	List p=head;
	for(int i=0;p->next!=NULL&&p->next->data->value<data->value;i++){
		p=p->next;
		//TODO
	}
	List newList=MakeList();
	newList->data=data;
	newList->next=p->next;
	p->next=newList;
}
//中序遍历输出二叉树 
void InOrder(TreeNode* root){
	if(root->left!=NULL){
		InOrder(root->left);
		//TODO
	}
	printf("%d ",root->value);
	if(root->right!=NULL){
		InOrder(root->right);
		//TODO
	}
}

int main(){
	List head=MakeList();
	List p=head;
	//a为权值数组 
	int a[6]={1,1,2,3,4,5};
	for(int i=0;i<6;i++){
		//向链表中添加树结点 
		TreeNode*q=CreateTreeNode(a[i]);
		AddData(&p,q);
		//TODO
	}
	//规定链表最后一个元素的权值为INF（为了插入函数不出错） 
	TreeNode*q=CreateTreeNode(1000);
	p->data=q;
	//开始扩大树 
	for(int i=0;i<5;i++){
		p=head;
		int sum=p->data->value+p->next->data->value;
		//每次增加一个根结点，并接上选出来的最小两个树结点 
		TreeNode*root=CreateTreeNode(sum);
		root->left=p->data;
		root->right=p->next->data;
		//将新建的根树插到合适的位置 
		InsertANumber(head,root);
		//删除前面的树结点，移动头指针 
		head=p->next->next;
		free(p->next);
		free(p);
		//TODO
	}
	//中序遍历打印树 
	InOrder(head->data);
	return 0; 
}
