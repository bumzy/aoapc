#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int MAXM = 55;
const int MAXN = 1000 + 10;
int T, m, n, cnt[MAXN][4];
char str[MAXM][MAXN], ans[MAXN];
map<char, int> charToInt;
char intToChar[5] = "ACGT";

void init(){
	charToInt['A'] = 0;
	charToInt['C'] = 1;
	charToInt['G'] = 2;
	charToInt['T'] = 3;
}

int main(){
	init();
	scanf("%d", &T);
	while(T--){
		memset(str, 0, sizeof(str));
		memset(cnt, 0, sizeof(cnt));
		memset(ans, 0, sizeof(ans));
		scanf("%d%d", &m, &n);
		for(int i = 0; i < m; ++i){
			scanf("%s", str[i]);
			for(int j = 0; j < n; ++j){
				cnt[j][charToInt[str[i][j]]]++;
			}
		}
		int sum = 0;
		for(int i = 0; i < n; ++i){
			int maxIdx = 0;
			for(int j = 1; j < 4; ++j){
				if(cnt[i][j] > cnt[i][maxIdx]){
					maxIdx = j;
				}
			}
			ans[i] = intToChar[maxIdx];
			sum += m - cnt[i][maxIdx];
		}
		printf("%s\n%d\n", ans, sum);
	}
	return 0;
}