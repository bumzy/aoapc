/**
 * UVa1594 - Ducci Sequence
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=836&page=show_problem&problem=4469
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int num[20], T, n;

bool check(int num[], int n){
	for(int i = 0; i < n; ++i)
		if(num[i] != 0)
			return false;
	return true;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &num[i]);
		int cnt = 1000;
		while(cnt-- && !check(num, n)){
			int first = num[0];
			for(int i = 0; i < n - 1; ++i){
				num[i] = abs(num[i] - num[i+1]);
			}
			num[n-1] = abs(num[n-1] - first);
		}
		if(check(num, n))
			printf("ZERO\n");
		else
			printf("LOOP\n");
	}
	return 0;
}