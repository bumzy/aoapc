#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10;
int n, m, idx = 0;
int H[MAXN][MAXN], V[MAXN][MAXN], ans[MAXN];

int main(){
	while(scanf("%d%d", &n, &m) == 2){
		memset(H, 0, sizeof(H));
		memset(V, 0, sizeof(V));
		memset(ans, 0, sizeof(ans));
		char op[4];
		int i, j;
		while(m--){
			scanf("%s%d%d", op, &i, &j);
			if(op[0] == 'H'){
				H[i][j] = 1;
			}else{
				V[j][i] = 1;
			}
		}
		for(int i = n; i >= 1; --i){
			for(int j = n; j >= 1; --j){
				if(H[i][j]) H[i][j] = H[i][j+1] +1;
				if(V[i][j]) V[i][j] = V[i+1][j] + 1;
			}
		}
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				for(int k = min(H[i][j], V[i][j]); k >= 1; --k){
					if(H[i+k][j] >= k && V[i][j+k] >= k){
						ans[k]++;
					}
				}
			}
		}
		if(idx)
			puts("\n**********************************\n");
		printf("Problem #%d\n\n", ++idx);
		int find = 0;
		for(int i = 1; i <= n; ++i){
			if(ans[i])
				printf("%d square (s) of size %d\n", ans[i], i), find = 1;
		}
		if(!find)
			puts("No completed squares can be found.");
	}
	return 0;
}