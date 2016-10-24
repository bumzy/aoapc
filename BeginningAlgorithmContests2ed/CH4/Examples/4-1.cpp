#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int ALPHA_SIZE = 26;
char s1[128], s2[128];
int cnt1[ALPHA_SIZE] ={0}, cnt2[ALPHA_SIZE] = {0};

void count(char s[], int cnt[], int len){
	for(int i = 0; i < len; ++i){
		cnt[s[i] - 'A']++;
	}
}

bool check(int cnt1[], int cnt2[]){
	for(int i = 0; i < ALPHA_SIZE; ++i){
		if(cnt1[i] != cnt2[i]){
			return false;
		}
	}
	return true;
}

int main(){
	while(scanf("%s%s", s1, s2) == 2){
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		count(s1, cnt1, len1);
		count(s2, cnt2, len2);
		sort(cnt1, cnt1 + ALPHA_SIZE);
		sort(cnt2, cnt2 + ALPHA_SIZE);
		printf("%s\n", check(cnt1, cnt2) ? "YES" : "NO");
	}
	return 0;
}