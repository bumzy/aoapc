/**
 * UVa12096 - The SetStack Computer
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=835&page=show_problem&problem=3248
 */
#include <cstdio>
#include <set>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

int T, N, n = 0;
typedef set<int> Set;
map<Set, int> Set2IDMap;
map<int, Set> ID2SetMap;
stack<int> st;

int ID(Set x) {
	if (Set2IDMap.count(x)) return Set2IDMap[x];
	Set2IDMap[x] = n;
	ID2SetMap[n] = x;
	return n++;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		while (!st.empty()) st.pop();
		while (N--) {
			char op[12];
			scanf("%s", op);
			if (op[0] == 'P') st.push(ID(Set()));
			else if (op[0] == 'D') st.push(st.top());
			else {
				Set x1 = ID2SetMap[st.top()]; st.pop();
				Set x2 = ID2SetMap[st.top()]; st.pop();
				Set x;
				if (op[0] == 'U') set_union(ALL(x1), ALL(x2), INS(x));
				else if (op[0] == 'I') set_intersection(ALL(x1), ALL(x2), INS(x));
				else if (op[0] == 'A') {
					x = x2;
					x.insert(ID(x1));
				}
				st.push(ID(x));
			}
			printf("%lu\n", ID2SetMap[st.top()].size());
		}
		printf("***\n");
	}
	return 0;
}