#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100 +10;
char str[MAXN];

int less(const char *s, int p, int q){
	int n = strlen(s);
	for(int i = 0; i < n; ++i){
		if(s[(p+i)%n] != s[(q+i)%n])
			return s[(p+i)%n] < s[(q+i)%n];
	}
	return 0;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%s", str);
		int ans = 0;
		int n = strlen(str);
		for(int i = 1; i < n; ++i){
			if(less(str, i, ans)){
				ans = i;
			}
		}
		for(int i = 0; i < n; ++i){
			putchar(str[(ans+i)%n]);
		}
		printf("\n");
	}
	return 0;
}