#include <stdio.h>
#include<stdlib.h>
typedef struct MapNode{
	int value;
	int beginPoint;
	int finalPoint;
}MapNode;

void ShellSort(MapNode*map,int m){
	int inc,i,j;
	int Sedgewick[] = {260609,146305,64769,36289,16001,8929,
					3905,2161,929, 505,209, 109, 41,
					 19, 5, 1, 0};//或者gn+1=3gn+1 
	int si;
	for(si=0;Sedgewick[si]>=m;si++);//用来得到一个初始的恰当的inc。 
	for(int inc=Sedgewick[si];inc>0;inc=Sedgewick[++si]){
		for(i=inc;i<m;i++){
			int t=map[i].value;
			for(j=i;j>=inc&&t<map[j-inc].value;j-=inc){
				MapNode temp=map[j];
				map[j]=map[j-inc];
				map[j-inc]=temp;
				//TODO
			}
			map[j].value=t;
			//TODO
		}
		//TODO
	}
}

int IsIn(int point,MapNode *map,int N){
	for(int i=0;i<N;i++){
		if(map[i].beginPoint==point||map[i].finalPoint==point){
			return 1;
			//TODO
		}
		//TODO
	}
	return 0;
} 

int main(){
	int m;
	scanf("%d",&m);
	MapNode map[m];
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&map[i].beginPoint,&map[i].finalPoint,&map[i].value);
		//TODO
	}
	ShellSort(map,m);
	MapNode tree[m];
	tree[0]=map[0];
	int count=1;
	for(int i=1;i<m;i++){
		//若边的两个顶点都在tree集合里会构成圈 
		if(!(IsIn(map[i].beginPoint,tree,count)&&IsIn(map[i].finalPoint,tree,count))){
			count++;
			tree[count-1]=map[i];
			//TODO
		}
		//TODO
	}
	for(int i=0;i<count;i++){
		printf("%d\t%d\t%d\n",tree[i].beginPoint,tree[i].finalPoint,tree[i].value);
		//TODO
	}
	return 0; 
}
