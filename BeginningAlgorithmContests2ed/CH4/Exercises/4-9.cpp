/**
 * UVa 1591 - Data Mining
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=833&page=show_problem&problem=4466
 * 解题思路：http://blog.csdn.net/code4101/article/details/38540759
 * 疑问：A,B的范围怎么确定，题目中K<=N*SQ错了吧，应该是K>=N*SQ吧？
 */
#include <cstdio>
using namespace std;

int main(){
	long long n, sp, sq;
	while(scanf("%lld%lld%lld", &n, &sp, &sq) == 3){
		long long minK = 1LL << 62, a = 0, b = 0;
		for(int i = 0; i < 32; ++i){
			for(int j = 0; j < 32; ++j){
				long long maxPofs = (n - 1) * sp;
				long long k = ((maxPofs + (maxPofs << i)) >> j) + sq;
				if(k >= n * sq && k < minK) minK = k, a = i, b =j;
			}
		}
		printf("%lld %lld %lld\n", minK, a, b);
	}
	return 0;
}