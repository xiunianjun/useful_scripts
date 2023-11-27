#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char value;
	Node*bottom;
}Node;

typedef struct Stack{
	int lenth;
	Node* top;
}Stack;

Node* CreateStackNode(){
	Node * p=(Node*)malloc(sizeof(Node));
	p->value=0;
	p->bottom=NULL;
	return p;
}

void Push(Stack *stack,char ch){
	Node *p=CreateStackNode();
	p->value=ch;
	p->bottom=(*stack).top;
	(*stack).lenth++;
	(*stack).top=p;
}

char Pop(Stack *stack){
	Node* p=(*stack).top;
	char number=(*stack).top->value;
	(*stack).top=(*stack).top->bottom;
	(*stack).lenth--;
	return number;
}

int main(){
	Stack stack;
	stack.top=CreateStackNode();
	stack.lenth=0;
	char*str=(char*)malloc(sizeof(char)*100);
	scanf("%s",str);
	for(int i=0;i<strlen(str);i++){
		if(str[i]>=48&&str[i]<=57){
			Push(&stack,str[i]);
			//TODO
		}
		else{
			char ch1=Pop(&stack);
			char ch2=Pop(&stack);
			switch (str[i]) {
				case '/':
				case '¡Â':
					 Push(&stack,(ch2-48)/(ch1-48)+48);
					//TODO
					break;
				case 'X':
				case '¡Á':
				case '*':
					Push(&stack,(ch2-48)*(ch1-48)+48);
					//TODO
					break;
				case '+':
					Push(&stack,(ch2-48)+(ch1-48)+48);
					break;
				case '-':
					Push(&stack,(ch2-48)-(ch1-48)+48);
					break;
				default:
				//	exit(0);
				break;
			}
		}
		//TODO
	}
	printf("%c\n",stack.top->value);
	free(str);
	free(stack.top); 
	return 0; 
}
