#include <stdio.h>
#include<stdlib.h>
//��������� 
typedef struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int value;
}TreeNode;
//���������� 
typedef struct Link{
	TreeNode* data;
	Link *next;
}Link;
typedef Link*  List;

//���������ĺ���������Ϊ�����ڵ��Ȩֵ 
TreeNode* CreateTreeNode(int value){
	TreeNode*q=(TreeNode*)malloc(sizeof(TreeNode));
	q->value=value;
	q->left=NULL;
	q->right=NULL;
	return q;
}
//����������ĺ���������һ��ֵΪ�յ������� 
List MakeList(){
	List list=(List)malloc(sizeof(struct Link));
	list->next=NULL;
	list->data=NULL;
	return list;
}
//�������ĩβ����µ������ 
void AddData(List *list,TreeNode* n){
	(*list)->data=n;
	(*list)->next=MakeList();
	(*list)=(*list)->next;
}
//���ض�Ȩֵ�������������ĳ��λ�� 
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
//���������������� 
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
	//aΪȨֵ���� 
	int a[6]={1,1,2,3,4,5};
	for(int i=0;i<6;i++){
		//���������������� 
		TreeNode*q=CreateTreeNode(a[i]);
		AddData(&p,q);
		//TODO
	}
	//�涨�������һ��Ԫ�ص�ȨֵΪINF��Ϊ�˲��뺯�������� 
	TreeNode*q=CreateTreeNode(1000);
	p->data=q;
	//��ʼ������ 
	for(int i=0;i<5;i++){
		p=head;
		int sum=p->data->value+p->next->data->value;
		//ÿ������һ������㣬������ѡ��������С��������� 
		TreeNode*root=CreateTreeNode(sum);
		root->left=p->data;
		root->right=p->next->data;
		//���½��ĸ����嵽���ʵ�λ�� 
		InsertANumber(head,root);
		//ɾ��ǰ�������㣬�ƶ�ͷָ�� 
		head=p->next->next;
		free(p->next);
		free(p);
		//TODO
	}
	//���������ӡ�� 
	InOrder(head->data);
	return 0; 
}
