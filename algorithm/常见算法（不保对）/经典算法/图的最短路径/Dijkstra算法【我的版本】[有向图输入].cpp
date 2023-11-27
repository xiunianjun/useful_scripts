#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#define INF 10000
//µÝ¹é»ØËÝ 
void PrintPath(int firstPoint,int lastPoint,int lastStation[]){
	if(lastPoint==firstPoint){
		printf("%d",lastPoint+1);
		return;
		//TODO
	}
	PrintPath(firstPoint,lastStation[lastPoint],lastStation);
	printf("%d",lastPoint+1);
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	
	int graph[n][n];
	int flag[n];
	int distance[n];
	int lastStation[n];
	for(int i=0;i<n;i++){
		flag[i]=0;
		distance[i]=INF;
		lastStation[i]=-1;
		for(int j=0;j<n;j++){
			graph[i][j]=INF;
		}
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		graph[a-1][b-1]=c;
	}
	
	
	flag[0]=1;
	distance[0]=0;
	for(int i=0;;){
		
		int isConti=0;
		int minINdex=-1;
		int min=INF;
		
		for(int j=0;j<n;j++){
			
			if(flag[j]==1){
				continue;
			}
			
			isConti=1;
			if(distance[j]>distance[i]+graph[i][j]){
				distance[j]=distance[i]+graph[i][j];
				lastStation[j]=i;
				//TODO
			}
			if(min>distance[j]){
				min=distance[j];
				minINdex=j; 
			}
		}
		
		i=minINdex;
		if(minINdex>=0){
			flag[minINdex]=1;
		}
		if(isConti==0){
			break;
		}
		
	}
	
	
	for(int i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\n",i+1,flag[i],lastStation[i]+1,distance[i]);
	}
	
	
	int firstPoint,lastPoint;
	scanf("%d %d",&firstPoint,&lastPoint);
	PrintPath(firstPoint-1,lastPoint-1,lastStation);
	return 0;
}
