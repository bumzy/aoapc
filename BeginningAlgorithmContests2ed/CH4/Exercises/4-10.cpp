/**
 * UVa 815 - Flooded!
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=833&page=show_problem&problem=756
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 40 * 40;
int m, n, region[MAX];

int main(){
	int kase = 0;
	while(scanf("%d%d", &m, &n) == 2 && m * n){
		int num = m * n;
		for(int i = 0; i < num; ++i){
			scanf("%d", &region[i]);
		}
		double total;
		scanf("%lf", &total);
		total /= 100;
		sort(region, region + num);
		double level = 0.0, cnt = 0;
		for(int i = 0; i < num - 1 && total > 0; ++i){
			if(total > (region[i+1] - region[i]) * (i + 1)){
				total -= (region[i+1] - region[i]) * (i + 1);
			}else{
				level = region[i] + total / (i + 1);
				total = 0;
			}
			cnt++;
		}
		if(total > 0){
			level = region[num-1] + total / num;
			cnt = num;
		}
		printf("Region %d\n", ++kase);
		printf("Water level is %.2lf meters.\n", level);
		printf("%.2lf percent of the region is under water.\n", (double)cnt / num * 100);
		printf("\n");
	}
	return 0;
}