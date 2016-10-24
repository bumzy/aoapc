#include <cstdio>
#include <cstring>
using namespace std;

const int MAXLEN = 100;
int left, chance;
char s1[MAXLEN], s2[MAXLEN];
int win, lose;
bool vis[26];

void guess(char ch){
	int bad = 1;
	for(int i = 0; i < strlen(s1); ++i){
		if(s1[i] == ch){
			--left;
			s1[i] = ' ';
			bad = 0;
		}
	}
	if(bad) --chance;
	if(!chance) lose = 1;
	if(!left) win = 1;
}

int main(){
	int rnd;
	while(scanf("%d%s%s", &rnd, s1, s2) == 3 && rnd != -1){
		memset(vis, 0, sizeof(vis));
		win = lose = 0;
		left = strlen(s1);
		chance = 7;
		for(int i = 0; i < strlen(s2); ++i){
			if(vis[s2[i] - 'a'] == false){
				guess(s2[i]);
				vis[s2[i] - 'a'] = true;
				if(win || lose) break;
			}
		}
		printf("Round %d\n", rnd);
		if(win) printf("You win.\n");
		else if(lose) printf("You lose.\n");
		else printf("You chickened out.\n");
	}
	return 0;
}