#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAXN 1000
 
int n,a[MAXN],maxA[MAXN],minA[MAXN];
 
int maxSubsequenceMul() {
	maxA[0] = minA[0] = a[0];
	int ans = a[0];
	for (int i = 1; i < n; i++) {
		maxA[i] = max(max(a[i], minA[i - 1] * a[i]), maxA[i - 1] * a[i]);
		minA[i] = min(min(a[i], minA[i - 1] * a[i]), maxA[i - 1] * a[i]);
		ans = max(ans, maxA[i]);
	}
	return ans;
}
 
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d", maxSubsequenceMul());
}
