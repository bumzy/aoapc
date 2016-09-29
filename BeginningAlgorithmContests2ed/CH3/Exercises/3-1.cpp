#include <cstdio>
using namespace std;

const int MAXN = 85;
int N;
char str[MAXN];

int main(){
	scanf("%d", &N);
	while(N--){
		scanf("%s", str);
		int score = 0, i = 0, j = 0;
		while(str[i] != '\0'){
			if(str[i] == 'O'){
				++j;
			}else{
				j = 0;
			}
			score += j;
			++i;
		}
		printf("%d\n", score);
	}
	return 0;
}