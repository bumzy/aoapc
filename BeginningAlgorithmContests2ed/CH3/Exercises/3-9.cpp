#include <cstdio>
#include <cstring>
using namespace std;

char s[1024000], t[1024000];

int main(){
	while(scanf("%s%s", s, t) == 2){
		int len_s = strlen(s);
		int len_t = strlen(t);
		int i = 0, j = 0;
		while(i < len_s && j < len_t){
			if(s[i] == t[j]){
				++i;
				++j;
			}else{
				++j;
			}
		}
		if(i == len_s){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}