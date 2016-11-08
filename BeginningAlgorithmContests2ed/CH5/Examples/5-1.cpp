/**
 * UVa10474 - Where is the Marble?
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=835&page=show_problem&problem=1415
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10000 + 10;
int N, Q, num[MAXN], kase = 0;

int main() {
	while (scanf("%d%d", &N, &Q) == 2 && !(N == 0 && Q == 0)) {
		for (int i = 0; i < N; ++i)
			scanf("%d", &num[i]);
		sort(num, num + N);
		printf("CASE# %d:\n", ++kase);
		while (Q--) {
			int x;
			scanf("%d", &x);
			int p = lower_bound(num, num + N, x) - num;
			if (num[p] == x) printf("%d found at %d\n", x, p + 1);
			else printf("%d not found\n", x);
		}
	}
	return 0;
}