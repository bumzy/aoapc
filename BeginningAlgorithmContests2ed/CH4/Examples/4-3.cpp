#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 30;
int N, k, m;
bool vis[MAXN];

int go(int pos, int d, int t){
	while(t--){
		do{
			pos += d;
			pos = (pos + N - 1) % N + 1;
		}while(vis[pos] == true);
	}
	return pos;
}

int main(){
	while(scanf("%d%d%d", &N, &k, &m) == 3 && N != 0){
		memset(vis, 0, sizeof(vis));
		int left = N, i = 0, j = N+1;
		while(left){
			i = go(i, 1, k);
			j = go(j, -1, m);
			vis[i] = vis[j] = true;
			if(i != j){
				printf("%3d%3d", i, j);
				left -= 2;
			}else{
				printf("%3d", i);
				left--;
			}
			if(left) printf(",");
		}
		printf("\n");
	}
	return 0;
}