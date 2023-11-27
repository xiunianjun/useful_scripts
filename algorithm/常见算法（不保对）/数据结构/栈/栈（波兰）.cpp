#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	double data;
	struct Node *p;
}Node;

typedef struct{
	int number;
	Node *top;
}Stack;

void Push(Stack *stack,double e);
double Pop(Stack *stack);

int main()
{
	Stack stack;
	stack.number=0;
	stack.top=(Node*)malloc(sizeof(Node));
	char *string=(char*)malloc(20*sizeof(char));
	scanf("%s",string);
	double number[strlen(string)+1];
	int flag=0;
	int lenth=strlen(string);
	int index=0;
	for(int i=0;i<lenth+1;i++){
		if(string[i]=='('){
			flag=1;
			continue;
			//TODO
		}
		else if(string[i]>=48&&string[i]<=57){

			if(flag){
				do{
					number[index]*=10;
					number[index]+=string[i]-48;
					i++;
				}while(string[i]!='.');
				i++;
				double tail=0;
				do{
					tail/=10;
					tail+=(double)(string[i]-48)/10;
					i++;
				}while(string[i]!=')');
				number[index]+=tail;
				index++;
				flag=0;
				//TODO
			}
			else{
                number[index]=string[i]-48;
                index++;
			}
			//TODO
		}
		else{
			continue;
		}
	}
	int count=0;
	for(int i=0;i<lenth;i++){
		int x=i;
		if(string[i]=='('){
			Push(&stack,number[count]);
			count++;
			do{
				i++;
			}while(string[i]!=')');
		}
		else if(string[i]>=48&&string[i]<=57){
            Push(&stack,number[count]);
            count++;
		}
		else
		{
			double d1=Pop(&stack);
			double d2=Pop(&stack);
			if(string[x]=='*'){
				Push(&stack,d2*d1);
				//TODO
			}
			else if(string[x]=='/'){
				Push(&stack,d2/d1);
				//TODO
			}
			else if(string[x]=='-'){
				Push(&stack,d2-d1);
				//TODO
			}
			else if(string[x]=='+'){
				Push(&stack,d2+d1);
				//TODO
			}
		}
	}
	printf("%f",stack.top->data);
	return 0;
}

void Push(Stack *stack,double e)
{
	Node* pS=(Node*)malloc(sizeof(Node));
	pS->data=e;
	pS->p=stack->top;
	stack->top=pS;
	stack->number++;
}
double Pop(Stack *stack)
{
	double num=stack->top->data;
	Node*temp=stack->top;
	stack->top=temp->p;
	free(temp);
	stack->number--;
	return num;
}
