/**
 * UVa10935 - Throwing cards away I
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=836&page=show_problem&problem=1876
 */
#include <cstdio>
#include <queue>
using namespace std;

int n;
queue<int> q;

int main(){
	while(scanf("%d", &n) != EOF && n){
		bool first = true;
		while(!q.empty())
			q.pop();
		for(int i = 1; i <= n; ++i)
			q.push(i);
		printf("Discarded cards:");
		while(q.size() >= 2){
			int x1 = q.front(); q.pop();
			int x2 = q.front(); q.pop();
			if(first){
				first = false;
				printf(" %d", x1);
			}else{
				printf(", %d", x1);
			}
			q.push(x2);
		}
		printf("\n");
		printf("Remaining card: %d\n", q.front());
	}
	return 0;
}