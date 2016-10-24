#include <cstdio>
using namespace std;

const int MAXN = 1000 + 10;
int m;
unsigned int ip[MAXN], minAddr = 0, maskAddr;

unsigned int readIP(){
	unsigned int addr[4], ret = 0;
	scanf("%d.%d.%d.%d", &addr[3], &addr[2], &addr[1], &addr[0]);
	for(int i = 0; i < 4; ++i){
		ret |= addr[i] << (i*8);
	}
	return ret;
}

void printAddr(unsigned int addr){
	for(int i = 3; i >= 0; --i){
		if(i != 3) printf(".");
		printf("%u", (addr >> (i*8)) & 0xff);
	}
	printf("\n");
}

int main(){
	while(scanf("%d", &m) == 1){
		for(int i = 0; i < m; ++i){
			ip[i] = readIP();
		}
		int bit;
		bool flag = true;
		for(bit = 31; bit >= 0; --bit){
			unsigned int mask = 0x1 << bit;
			for(int i = 1; i < m; ++i){
				if((ip[i] & mask) != (ip[0] & mask)){
					flag = false;
					break;
				}
			}
			if(!flag) break;
		}
		maskAddr = ~((0x1LL << (bit+1)) - 1);
		minAddr = maskAddr & ip[0];
		printAddr(minAddr), printAddr(maskAddr);
	}
	return 0;
}