#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

const char *rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *msg[] = {"not a palindrome", "a regular palindrome",
						"a mirrored string", "a mirrored palindrome"};

char r(char ch){
	if(isalpha(ch)) return rev[ch-'A'];
	else return rev[ch-'0'+25];
}

int main(){
	char str[24];
	while(scanf("%s", str) != EOF){
		int len = strlen(str), p = 1, m = 1;
		for(int i = 0; i <= len/2; ++i){
			if(str[i] != str[len-i-1]) p = 0;
			if(r(str[i]) != str[len-i-1]) m = 0;
		}
		printf("%s -- is %s.\n\n", str, msg[m*2+p]);
	}
	return 0;
}