#include <stdio.h>

int DFS(int a[],int na,int b[],int nb){
	if(na==0)
		return 1;
	if(a[0]!=b[0])
		return 0;
	if(na!=nb)
		return 0;
		
	int aLeft[na],bLeft[na],aRight[na],bRight[na];
	int aLeftCount=0,bLeftCount=0,aRightCount=0,bRightCount=0;
	
	for(int i=1;i<na;i++){
		if(a[i]<a[0])
			aLeft[aLeftCount++]=a[i];
		else if(a[i]>a[0])
			aRight[aRightCount++]=a[i];
		if(b[i]<b[0])
			bLeft[bLeftCount++]=b[i];
		else if(b[i]>b[0])
			bRight[bRightCount++]=b[i];
	}
	
	int boolLeft=DFS(aLeft,aLeftCount,bLeft,bLeftCount);
	int boolRight=DFS(aRight,aRightCount,bRight,bRightCount);
	
	return boolLeft&&boolRight;
} 

int main(){
	int a[4]={3,1,2,4};
	int b[4]={3,4,1,2};
	int result=DFS(a,4,b,4);
	printf("%d",result);
	return 0;
}
