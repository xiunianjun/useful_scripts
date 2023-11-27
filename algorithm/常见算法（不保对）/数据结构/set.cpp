#include <stdio.h>
#include <set>
using namespace std; 

int main(){
	set<int> name={0,9,8,9,7};
	set<int>::iterator it=name.begin();
	name.insert(9);
	name.insert(99);
	name.erase(name.find(8));
	for(;it!=name.end();it++){
		printf("%d ",*it);
		//TODO
	}
	printf("\n%d\n",*(name.find(7)));
	printf("\n%d\n",name.size());
	//set可以自动去重并且升序排列。 
	return 0;
}
