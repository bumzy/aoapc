#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5000;
const int DISPLAY_LIMIT = 50;
const int MAX_INT = 3000 + 10;
int digit[MAXN], reminder_pos[MAX_INT];
bool reminder_exit[MAX_INT];

int main(){
	int numerator, denominator, original_numerator, integer, reminder, quotient;
	while(scanf("%d%d", &numerator, &denominator) == 2){
		memset(reminder_pos, 0, sizeof(reminder_pos));
		memset(reminder_exit, 0, sizeof(reminder_exit));

		original_numerator = numerator;
		quotient = integer = numerator / denominator;
		reminder = numerator - denominator * quotient;

		int n = 0, cycle_pos = MAXN, cycle_len = 0;
		while(n < MAXN){
			if(reminder_exit[reminder]){
				cycle_pos = reminder_pos[reminder];
				cycle_len = n - cycle_pos;
				break;
			}else{
				reminder_exit[reminder] = true;
				reminder_pos[reminder] = n;
			}
			numerator = reminder * 10;
			quotient = numerator / denominator;
			reminder = numerator % denominator;
			digit[n] = quotient;
			++n;
		}
		printf("%d/%d = %d.", original_numerator, denominator, integer);
		int MIN = min(cycle_pos, DISPLAY_LIMIT);
		for(int i = 0; i < MIN; ++i){
			printf("%d", digit[i]);
		}
		if(cycle_pos < DISPLAY_LIMIT){
			printf("(");
			MIN = min(n, DISPLAY_LIMIT);
			for(int i = cycle_pos; i < MIN; ++i){
				printf("%d", digit[i]);
			}
			if(n > DISPLAY_LIMIT){
				printf("...");
			}
			printf(")\n");
		}
		printf("   %d = number of digits in repeating cycle\n\n", cycle_len);
	}
	return 0;
}