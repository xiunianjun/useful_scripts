#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 15

typedef struct{
	int value;
	int parent;
}SetType;

int Find(SetType array[],int n,int keyValue){//return index
	for(int i=0;i<n;i++){
		if(array[i].value==keyValue){
			while(array[i].parent!=-1)
				i=array[i].parent;
			return i+1;
			//TODO
		}
	}
	return -1;
}

//ÓÅ»¯£º
int FindParent(SetType array[],int index){
	if(array[index].parent<0){
		return index;
		//TODO
	}
	else{
		return array[index].parent=FindParent(array,array[index].parent);
	}
} 

void Union(SetType array[],int n,int keyOne,int keyTwo){
	int rootOne=Find(array,n,keyOne);
	int rootTwo=Find(array,n,keyTwo);
	if(rootOne!=rootTwo){
		if(array[rootOne].parent<array[rootTwo].parent){
			array[rootOne].parent+=array[rootTwo].parent;
			array[rootTwo].parent=rootOne;
			//TODO
		}
		else{
			array[rootTwo].parent+=array[rootOne].parent;
			array[rootOne].parent=rootTwo;
		}
	}
}

int main(){
	int n=10;
	SetType arrays[MAX_SIZE]={{1,-4},{2,0},{3,-3},{4,0},{5,2},{6,-3},{7,0},{8,2},{9,5},{10,5}};
	int result=Find(arrays,n,4);
	printf("%d",result);
}
