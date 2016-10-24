/**
 * UVa509
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=450
 */
#include <cstdio>
using namespace std;

char data[8][6400+10], parity[4];
int d, s, b, p, num;

int main(){
	int idx = 0;
	while(scanf("%d%d%d%s", &d, &s, &b, parity) == 4 && d != 0){
		p = parity[0] == 'E' ? 0 : 1;
		for(int i = 0; i < d; ++i){
			scanf("%s", data[i]);
		}
		int valid = 1;
		for(int i = 0; i < s*b; ++i){
			int bit = 0, nX = 0, pos = -1;
			for(int j = 0; j < d; ++j){
				if(data[j][i] != 'x'){
					bit ^= data[j][i] - '0';
				}else{
					pos = j;
					nX++;
				}
			}
			if(nX == 1){
				data[pos][i] = (p ^ bit) + '0';
			}else if(nX > 1 || (nX == 0 && bit != p)){
				valid = 0;
				break;
			}
		}
		printf("Disk set %d is ", ++idx);
		if(valid){
			num = 0;
			int bit_cnt = 0, sum = 0;
			printf("valid, contents are: ");
			for(int i = 0; i < b; ++i){
				for(int j = 0; j < d; ++j){
					if(i % d == j) continue;
					for(int k = 0; k < s; ++k){
						bit_cnt = (bit_cnt + 1) % 4;
						if(data[j][i * s + k] == '0') sum *= 2;
						else sum = sum * 2 + 1;
						if(!bit_cnt){
							printf("%X", sum);
							sum = 0;
						}
					}
				}
			}
			if(bit_cnt){
		        int over = 4 - bit_cnt;
		        sum = sum * (1<<over);
		        printf("%X", sum);
			}
			printf("\n");
		}else{
			printf("invalid.\n");
		}
	}
	return 0;
}