#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXLEN = 128;
char str1[MAXLEN], str2[MAXLEN];

int main(){
	while(scanf("%s%s", str1, str2) == 2){
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		int ans = MAXLEN * 2;
		for(int i = -len2; i <= len1; ++i){
			bool flag = true;
			for(int j = 0; j < len2; ++j){
				if(i + j >= 0 && i + j < len1 && str1[i+j] - '0' + str2[j] - '0' > 3){
					flag = false;
					break;
				}
			}
			if(flag){
				int res = i < 0 ? max(abs(i) + len1, len2) : max(i + len2, len1);
				ans = min(ans, res);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}