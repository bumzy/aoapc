#include <cstdio>
using namespace std;

const int MAXN = 10000 + 10;
int T;
int ans[MAXN][10];

int main(){
	int cnt[10] = {0};
	for(int i = 1; i < MAXN; ++i){
		int temp = i;
		while(temp != 0){
			cnt[temp%10]++;
			temp /= 10;
		}
		for(int j = 0; j < 10; ++j){
			ans[i][j] = cnt[j];
		}
	}
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		for(int j = 0; j < 10; ++j){
			if(j > 0) printf(" ");
			printf("%d", ans[n][j]);
		}
		printf("\n");
	}
	return 0;
}