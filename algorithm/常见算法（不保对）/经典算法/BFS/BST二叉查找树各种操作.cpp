#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
typedef struct ADTNode{
	ADTNode* left;
	ADTNode* right;
	int value;
}ADTNode;

ADTNode*CreateTreeNode(){
	ADTNode*p=(ADTNode*)malloc(sizeof(ADTNode));
	p->left=NULL;
	p->right=NULL;
	p->value=0;
	return p;
}

void CreateTree(ADTNode** root){
	char c;
	c=getchar();
	if(c==' '){
		*root=NULL;
		//TODO
	}
	else{
		*root=(ADTNode*)malloc(sizeof(ADTNode));
		if(*root==NULL){
			exit(1); 
			//TODO
		}
		(*root)->value=c-48;
		CreateTree(&((*root)->left));
		CreateTree(&((*root)->right));
	}
}

ADTNode* Find(ADTNode*tree,int key){
	if(tree==NULL){
		return NULL;
		//TODO
	}
	else if(tree->value==key){
		return tree;
		//TODO
	}
	else if(tree->value>key){
		return Find(tree->left,key);
		//TODO
	}
	else{
		return Find(tree->right,key);
	}
} 

ADTNode*FindMin(ADTNode*tree){
	if(tree==NULL){
		return NULL;
		//TODO
	}
	if(tree->left==NULL){
		return tree;
		//TODO
	} 
	return FindMin(tree->left);
}

ADTNode*FindMax(ADTNode*tree){
	if(tree==NULL){
		return NULL;
		//TODO
	}
	if(tree->right==NULL){
		return tree;
		//TODO
	}
	return FindMax(tree->right);
} 

ADTNode* InsertTree(ADTNode*tree,int key){
	if(tree==NULL){
		tree=CreateTreeNode();
		tree->value=key;
		//TODO
	}
	else{
		if(tree->value>key){
			tree->left=InsertTree(tree->left,key);
			//TODO
		}
		else if(tree->value<key){
			tree->right=InsertTree(tree->right,key);
			//TODO
		}
	}
	return tree;
}
//�ҵĴ�������𰸲��������ɾ�������
//�ҳ���������㸳ֵ�ݹ���ʵѧ���˰�
//����Ҳ������˷ѿռ� 
//void InsertTree(ADTNode** tree,int key){
//	if(Find(*tree,key)){
//		return;
//		//TODO
//	}
//	ADTNode*keyPosition=CreateTreeNode();
//	keyPosition->value=key;
//	ADTNode*p=*tree;
//	ADTNode*pre=p;
//	while(p){
//		pre=p;
//		if(p->value>key){
//			p=p->left;
//			//TODO
//		}
//		else if(p->value<key){
//			p=p->right;
//			//TODO
//		}
//		//TODO
//	}
//	if(pre==*tree)
//		*tree=keyPosition;
//	else{
//		if(pre->value>key){
//			pre->left=keyPosition;
//			//TODO
//		}
//		else{
//			pre->right=keyPosition;
//		}
//	}
//}

void PreOrder(ADTNode*tree){
	if(tree==NULL){
		return;
		//TODO
	}
	printf("%d",tree->value);
	PreOrder(tree->left);
	PreOrder(tree->right);
} 
/*
	����֮�������ɾ��
	��ɾ����㣬���Ǳ�������ִ���-1 
*/ 
ADTNode* DeleteNode(int key,ADTNode*tree){
	ADTNode* tmpCell;
	if(tree==NULL){
		return NULL;
		//TODO
	}
	else if(key<tree->value){
		tree->left=DeleteNode(key,tree->left);
		//TODO
	}
	else if(key>tree->value){
		tree->right=DeleteNode(key,tree->right);
		//TODO
	}
	else if(tree->left&&tree->right){
		tmpCell=FindMin(tree->right);
		tree->value=tmpCell->value;
		tree->right=DeleteNode(tree->value,tree->right);
	}
	else{
		tmpCell=tree;
		if(tree->left==NULL){
			tree=tree->right;
			//TODO
		}
		else{
			tree=tree->left;
		}
		free(tmpCell);
	}
	return tree;
} 
//�ҵĴ������ԭ����ֻ�ı���p��ֵ��û�иı�preָ��
//����ָ��p�ĺ��ӳ�ʼ��ΪNULL�����´�ӡʱ����
//����Ҫ��ô�������pre���ͺ��Ѹ�
//�����׼�𰸸����˵ݹ���ַ�
//����Ҳ���������һ�����ķ������͸ı�һ��˼·
//�Ѻ����ĳɷ��ؽṹָ������ͣ���㷵�ظ�ֵ
//���һ�����ɡ�˼����Insert�������� 
//ADTNode* DeleteNode(ADTNode*tree,int key){
//	//flag����0��1 
//	ADTNode*p=Find(tree,key);
//	if(p==NULL){
//		return NULL;
//		//TODO
//	}
//	if(p->left&&p->right){
//		ADTNode*min=FindMin(p->right);
//		p->value=min->value;
//		p->right=DeleteNode(p->right,p->value);
//		//TODO
//	}
//	else{
//		ADTNode*temp=p;
//		if(p->left==NULL)
//			p=p->right;
//		else
//			p=p->left;
//		free(temp);
//	} 
//	return tree;
//} 

int main() {
	ADTNode* tree=NULL;
	CreateTree(&tree);
	ADTNode*result=Find(tree,2);
	ADTNode*minResult=FindMin(tree);
	ADTNode*maxResult=FindMax(tree);
	if(result==NULL){
		printf("No finding!\n");
		//TODO
	}
	else{
		printf("%d\n",result->value);
	}
	printf("%d\t%d\n",minResult->value,maxResult->value);
	InsertTree(tree,2);
	PreOrder(tree);
	printf("\n");
	ADTNode* TREE=DeleteNode(2,tree);
	PreOrder(TREE);
	printf("\n");
	return 0;
}
