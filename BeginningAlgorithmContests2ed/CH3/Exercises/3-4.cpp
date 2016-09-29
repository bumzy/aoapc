#include <cstdio>
#include <cstring>
using namespace std;

int N;
char str[100];

int main(){
	scanf("%d", &N);
	while(N--){
		scanf("%s", str);
		int step = 1;
		int len = strlen(str);
		for(int step = 1; step <= len; ++step){
			if(len % step == 0){
				bool flag = true;
				for(int i = step; i < len; ++i){
					if(str[i] != str[i % step]){
						flag = false;
						break;
					}
				}
				if(flag){
					printf("%d\n", step);
					if(N > 0) printf("\n");
					break;
				}
			}
		}
	}
	return 0;
}