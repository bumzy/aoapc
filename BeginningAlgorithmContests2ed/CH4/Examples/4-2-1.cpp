#include <cstdio>
#include <cstring>
using namespace std;

const int MAXLEN = 1028;
bool solved[MAXLEN], visited[26];
char s1[MAXLEN], s2[MAXLEN];

bool check(bool solved[], int len){
	for(int i = 0; i < len; ++i){
		if(solved[i] == false)
			return false;
	}
	return true;
}

int main(){
	int idx;
	while(scanf("%d", &idx) == 1 && idx != -1){
		memset(solved, 0, sizeof(solved));
		memset(visited, 0, sizeof(visited));
		scanf("%s%s", s1, s2);
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		int stroke = 0;

		for(int i = 0; i < len2; ++i){
			bool flag = false;
			for(int j = 0; j < len1; ++j){
				if(s2[i] == s1[j]){
					solved[j] = true;
					flag = true;
				}
			}
			if(flag == false && visited[s2[i] - 'a'] == false){
				stroke++;
			}
			visited[s2[i] - 'a'] = true;
			if(check(solved, len1) || stroke == 7)
				break;
		}
		printf("Round %d\n", idx);
		if(check(solved, len1) && stroke < 7){
			printf("You win.\n");
		}else if(stroke == 7){
			printf("You lose.\n");
		}else{
			printf("You chickened out.\n");
		}
	}
	return 0;
}