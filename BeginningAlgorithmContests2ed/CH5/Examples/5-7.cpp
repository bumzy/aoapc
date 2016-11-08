/**
 * UVa136 - Ugly Numbers
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=835&page=show_problem&problem=72
 */
#include <cstdio>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef long long LL;
set<LL> s;
priority_queue<LL, vector<LL>, greater<LL> > pq;
const int coeff[] = {2, 3, 5};

int main(){
	LL x, x2;
	pq.push(1);
	s.insert(1);
	for(int i = 1; i <= 1500; ++i){
		x = pq.top();
		pq.pop();
		for(int j = 0; j < 3; ++j){
			x2 = x * coeff[j];
			if(!s.count(x2)){
				s.insert(x2);
				pq.push(x2);
			}
		}
	}
	printf("The 1500'th ugly number is %lld.\n", x);
	return 0;
}