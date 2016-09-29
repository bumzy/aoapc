#include <cstdio>
using namespace std;

const int MAXN = 100000 + 10;
int ans[MAXN] = {0};

int main(){
	int T, N;
	scanf("%d", &T);
	for(int i = 1; i < MAXN; ++i){
		int x = i, y = i;
		while(x > 0){
			y += x % 10;
			x /= 10;
		}
		if(ans[y] == 0 || i < ans[y]){
			ans[y] = i;
		}
	}
	while(T--){
		scanf("%d", &N);
		printf("%d\n", ans[N]);
	}
	return 0;
}