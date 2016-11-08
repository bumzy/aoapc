/**
 * UVa540 - Team Queue
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=835&page=show_problem&problem=481
 */
#include <cstdio>
#include <queue>
#include <list>
using namespace std;

int teamId[1000000], t, kase = 0;
list<queue<int> > q;

int main(){
	while(scanf("%d", &t) == 1 && t){
		q.clear();
		for(int i = 0; i < t; ++i){
			int num, id;
			scanf("%d", &num);
			while(num--){
				scanf("%d", &id);
				teamId[id] = i;
			}
		}
		printf("Scenario #%d\n", ++kase);
		for(;;){
			char op[24];
			scanf("%s", op);
			if(op[0] == 'E'){
				int x;
				scanf("%d", &x);
				list<queue<int> >::iterator it;
				for( it = q.begin(); it != q.end(); ++it){
					if(teamId[it->front()] == teamId[x]){
						it->push(x);
						break;
					}
				}
				if(it == q.end()){
					queue<int> tmp;
					tmp.push(x);
					q.push_back(tmp);
				}
			}else if(op[0] == 'D'){
				printf("%d\n", q.begin()->front());
				q.begin()->pop();
				if(q.begin()->empty())
					q.pop_front();
			}else
				break;
		}
		printf("\n");
	}
	return 0;
}