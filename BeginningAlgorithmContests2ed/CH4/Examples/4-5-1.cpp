#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100;
const int BASE = 10000;
int r, c, sheet[MAXN][MAXN], sheet2[MAXN][MAXN], ans[MAXN][MAXN];
bool idx[MAXN];

void copy(char type, int p, int q){
	if(type == 'R'){
		for(int i = 1; i <= c; ++i){
			sheet[p][i] = sheet2[q][i];
		}
	}else{
		for(int i = 1; i <= r; ++i){
			sheet[i][p] = sheet2[i][q];
		}
	}
}

void del(char type){
	memcpy(sheet2, sheet, sizeof(sheet));
	int cnt = type == 'R' ? r : c, cnt2 = 0;
	for(int i = 1; i <= cnt; ++i){
		if(idx[i] == false){
			copy(type, ++cnt2, i);
		}
	}
	if(type == 'R')
		r = cnt2;
	else
		c = cnt2;
}

void ins(char type){
	memcpy(sheet2, sheet, sizeof(sheet));
	int cnt = type == 'R' ? r : c, cnt2 = 0;
	for(int i = 1; i <= cnt; ++i){
		if(idx[i] == true){	
			copy(type, ++cnt2, 0);
		}
		copy(type, ++cnt2, i);
	}
	if(type == 'R')
		r = cnt2;
	else
		c = cnt2;
}

int main(){
	int kase = 0;
	while(scanf("%d%d", &r, &c) == 2 && r != 0){
		memset(sheet, 0, sizeof(sheet));
		for(int i = 1; i <= r; ++i){
			for(int j = 1; j <= c; ++j){
				sheet[i][j] = i * BASE + j;
			}
		}
		int n;
		scanf("%d", &n);
		while(n--){
			char cmd[4];
			scanf("%s", cmd);
			if(cmd[0] == 'E'){
				int r1, c1, r2, c2;
				scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
				swap(sheet[r1][c1], sheet[r2][c2]);
			}else{
				int m, x;
				scanf("%d", &m);
				memset(idx, 0, sizeof(idx));
				for(int i = 0; i < m; ++i){
					scanf("%d", &x);
					idx[x] = true;
				}
				if(cmd[0] == 'D'){
					del(cmd[1]);
				}else{
					ins(cmd[1]);
				}
			}
		}
		memset(ans, 0, sizeof(ans));
		for(int i = 1; i <= r; ++i){
			for(int j = 1; j <= c; ++j){
				ans[sheet[i][j] / BASE][sheet[i][j] % BASE] = i * BASE + j;
			}
		}
		if(kase > 0) printf("\n");
		printf("Spreadsheet #%d\n", ++kase);
		int q;
		scanf("%d", &q);
		while(q--){
			int r1, c1;
			scanf("%d%d", &r1, &c1);
			printf("Cell data in (%d,%d) ", r1, c1);
			if(ans[r1][c1] == 0) printf("GONE\n");
			else printf("moved to (%d,%d)\n", ans[r1][c1] / BASE, ans[r1][c1] % BASE);
		}
	}
	return 0;
}