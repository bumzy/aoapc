#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 10;
int g[MAXN][MAXN][MAXN][MAXN], n, m;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int countSquares(int s){
	int cnt = 0;
	for(int x = 1; x <= n - s; ++x){
		for(int y = 1; y <= n - s; ++y){
			int r = 1, sx = x, sy = y;
			for(int i = 0; i < 4; ++i){
				int ex = sx + dx[i], ey = sy + dy[i];
				for(int l = 0; l < s; ++l){
					r &= g[sx][sy][ex][ey];
					sx = ex, sy = ey;
					if(l < s - 1)
						ex += dx[i], ey += dy[i];
				}
			}
			cnt += r;
		}
	}
	return cnt;
}

int main(){
	int idx = 0;
	while(scanf("%d%d", &n, &m) == 2){
		memset(g, 0, sizeof(g));
		while(m--){
			char s[4];
			int i, j;
			scanf("%s%d%d", s, &i, &j);
			if(s[0] == 'H'){
				g[i][j][i][j+1] = g[i][j+1][i][j] = 1;
			}else if(s[0] == 'V'){
				g[j][i][j+1][i] = g[j+1][i][j][i] = 1;
			}
		}
		if(idx != 0)
			printf("\n**********************************\n\n");
		printf("Problem #%d\n\n", ++idx);
		int outPut = 0;
		for(int i = 1; i <= n; ++i){
			int amt  = countSquares(i);
			if(amt)
				printf("%d square (s) of size %d\n", amt, i);
			outPut |= amt;
		}
		if(!outPut)
			printf("No completed squares can be found.\n");
	}
	return 0;
}