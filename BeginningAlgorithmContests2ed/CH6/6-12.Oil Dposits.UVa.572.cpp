#include <cstdio>
#include <cstring>
#define MAX 101

using namespace std;

int m, n;
int idx[MAX][MAX];
char pic[MAX][MAX];

void dfs(int i, int j, int id){
	if(i < 0 || i >=m || j < 0 || j >=n) return;
	if(idx[i][j] != 0 || pic[i][j] == '*') return;
	idx[i][j] = id;
	for(int di = -1; di <= 1; ++di){
		for(int dj = -1; dj <= 1; ++dj){
			dfs(i + di, j + dj, id);
		}
	}
}

int main(){
	while(scanf("%d%d", &m, &n) == 2 && m != 0){
		for (int i = 0; i < m; ++i){
			scanf("%s", &pic[i]);
		}
		memset(idx, 0 , sizeof(idx));
		int cnt = 0;
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				if (idx[i][j] == 0 && pic[i][j] == '@'){
					dfs(i, j, ++cnt);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}