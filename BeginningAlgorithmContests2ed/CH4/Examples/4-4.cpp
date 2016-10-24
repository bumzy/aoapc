#include <cstdio>
#include <cstring>
using namespace std;

int code[8][1<<8];

char readchar(){
	for(;;){
		char ch = getchar();
		if(ch != '\n' && ch != '\r'){
			return ch;
		}
	}
}

int readint(int c){
	int v = 0;
	while(c--){
		v = v * 2 + readchar() - '0';
	}
	return v;
}

bool readcodes(){
	memset(code, 0, sizeof(code));
	code[1][0] = readchar();
	for(int len = 2; len <= 7; ++len){
		for(int i = 0; i < (1 << len) - 1; ++i){
			char ch = getchar();
			if(ch == EOF) return false;
			if(ch == '\n' || ch == '\r') return true;
			code[len][i] = ch;
		}
	}
	return true;
}

void printcodes(){
	for(int len = 1; len <= 7; ++len){
		for(int i = 0; i < (1 << len) - 1; ++i){
			if(code[len][i] == 0) return;
			printf("code[%d][%d] = %c\n", len, i, code[len][i]);
		}
	}
}

int main(){
	while(readcodes()){
		//printcodes();
		for(;;){
			int len = readint(3);
			if(len == 0) break;
			//printf("len = %d\n", len);
			for(;;){
				int v = readint(len);
				//printf("v = %d\n", v);
				if(v == (1 << len) - 1) break;
				putchar(code[len][v]);
			}
		}
		printf("\n");
	}
	return 0;
}