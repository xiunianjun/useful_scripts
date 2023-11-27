#include<stdlib.h>
#include <stdio.h>

typedef struct TreeNode{
	TreeNode*left;
	TreeNode*right;
	int value;
}TreeNode;
typedef struct QNode{
	TreeNode *treenode;
	QNode*next;
}QNode;

typedef struct Queue{
	QNode*front;
	QNode*rear;
}Queue;

QNode* CreateQNode(){
	QNode* q=(QNode*)malloc(sizeof(QNode));
	q->treenode=NULL;
	q->next=NULL;
	return q; 
}

void AddQ(Queue*queue,TreeNode*node){
	QNode*q=CreateQNode();
	q->treenode=node;
	if(!(queue->front)&&!(queue->rear)){
		queue->front=queue->rear=q;
	}
	else{
		queue->rear->next=q;
		queue->rear=q;
	}
}

void PrintQ(Queue*queue){
	if(queue->front==NULL){
		printf("The queue is Null!\n");
		return;
		//TODO
	}
	QNode* q=queue->front;
	while(q){
		printf("%d ",q->treenode->value);
		q=q->next;
		//TODO
	}
}

TreeNode* DeleteQ(Queue*queue){
	if(queue->front==NULL){
		printf("The queue is Null!\n");
		return NULL;
		//TODO
	}
	if(queue->front==queue->rear){
		queue->rear=NULL;
		//TODO
	}
	QNode*q=queue->front;
	TreeNode* number=q->treenode;
	queue->front=(queue->front)->next;
	free(q);
	return number;	
}

TreeNode* CreateTreeNode(){
	TreeNode*p=(TreeNode*)malloc(sizeof(TreeNode));
	p->value=0;
	p->left=NULL;
	p->right=NULL;
	return p;
}

void CreateTree(TreeNode** root){
	char c;
	c=getchar();
	if(c==' '){
		*root=NULL;
		//TODO
	}
	else{
		*root=CreateTreeNode();
		if(*root==NULL){
			exit(1); 
			//TODO
		}
		(*root)->value=c-48;
		CreateTree(&((*root)->left));
		CreateTree(&((*root)->right));
	}
}

void FloorTraversal(TreeNode *tree){
	Queue queue;
	queue.front=NULL;
	queue.rear=NULL;
	AddQ(&queue,tree);
	TreeNode*p=tree;
	while(queue.front){
		p=DeleteQ(&queue);
		printf("%d ",p->value);
		if(p->left!=NULL){
			AddQ(&queue,p->left);
		}
		if(p->right!=NULL){
			AddQ(&queue,p->right);
		}
	}
}

int main(){
	TreeNode* tree=(TreeNode*)malloc(sizeof(TreeNode));
	CreateTree(&tree);
	//PreOrder(tree);
//	InOrder(tree);
	FloorTraversal(tree);
	return 0; 
}
