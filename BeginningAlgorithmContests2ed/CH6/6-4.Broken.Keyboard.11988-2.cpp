#include <cstdio>
#include <cstring>
#define MAXN 100000 + 5
using namespace std;

int main(int argc, char const *argv[])
{
	char s[MAXN];
	int next[MAXN];
	while(scanf("%s", s + 1) == 1) {
	    int len = strlen(s + 1);
	    next[0] = 0;
	    int curr = 0, last = 0;
	    for(int i = 1; i <= len; ++i){
	    	if(s[i] == '['){
	    		curr = 0;
	    	}else if(s[i] == ']'){
	    		curr = last;
	    	}else{
	    		next[i] = next[curr];
	    		next[curr] = i;
	    		if(curr == last) last = i;
	    		curr = i;
	    	}
	    }
	    for(int i = next[0]; i != 0; i = next[i]){
	    	printf("%c", s[i]);
	    }
	    printf("\n");
	}
	return 0;
}