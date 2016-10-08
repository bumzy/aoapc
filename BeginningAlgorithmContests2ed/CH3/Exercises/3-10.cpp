/*
* UVa 1587 - Box
* https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=448&page=show_problem&problem=4462
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 6;
struct Rect{
	int s, l;
} rect[N];

bool cmp(const Rect &r1, const Rect &r2){
	if(r1.s != r2.s) return r1.s < r2.s;
	else return r1.l < r2.l;
}

int main(){
	int a, b;
	while(scanf("%d%d", &a, &b) == 2){
		rect[0].s = min(a, b);
		rect[0].l = max(a, b);
		for(int i = 1; i < N; ++i){
			scanf("%d%d", &a, &b);
			rect[i].s = min(a, b);
			rect[i].l = max(a, b);
		}
		sort(rect, rect + N, cmp);
		bool flag = true;
		for(int i = 0; i < N; i += 2){
			if(rect[i].s != rect[i+1].s || rect[i].l != rect[i+1].l){
				flag = false;
			}
		}
		if(rect[0].s != rect[2].s || rect[0].l != rect[4].s || rect[2].l != rect[4].l){
			flag = false;
		}
		printf("%s\n", flag ? "POSSIBLE" : "IMPOSSIBLE");
	}
	return 0;
}