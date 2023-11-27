#include <stdio.h>

int FindThreeMax(int a,int b,int c){
	if(a>b)
		return a>c?a:c;
	else
		return b>c?b:c;
}

int FindMax(int a[],int left,int right){
	int MaxLeftSum,MaxRightSum;
	int MaxLeftBorder,MaxRightBorder;
	int leftBorder,rightBorder;
	int center;
	
	if(left==right){
		return a[left]>0?a[left]:0;
	}
	
	center=(left+right)/2;
	MaxLeftSum=FindMax(a,left,center);
	MaxRightSum=FindMax(a,center+1,right);
	
	MaxLeftBorder=0,leftBorder=0;
	for(int i=center;i>=left;i--){
		leftBorder+=a[i];
		if(MaxLeftBorder<leftBorder){
			MaxLeftBorder=leftBorder;
		}
	}
	
	MaxRightBorder=0,rightBorder=0;
	for(int i=center+1;i<=right;i++){
		rightBorder+=a[i];
		if(MaxRightBorder<rightBorder){
			MaxRightBorder=rightBorder;
		}
	}
	
	return FindThreeMax(MaxLeftBorder+MaxRightBorder,MaxLeftSum,MaxRightSum);
}

int main(){
	int a[]={4,-3,5,-2,-1,2,6,-2};
	int result=FindMax(a,0,7);
	printf("%d",result);
	return 0;
}
