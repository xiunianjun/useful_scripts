#include <stdio.h>
#include <vector>
using namespace std;

int main(){
	vector<int> vi;
	vector<int>::iterator it;
	for(int i=0;i<5;i++){
		vi.push_back(i); 
		//TODO
	}
	it=vi.begin();
	vi.insert(vi.begin()+2,-1);
	for(int i=0;i<vi.size();i++){
		printf("%d ",*(it+i));
		//TODO
	}
	return 0;
}
