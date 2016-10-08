/*
*UVa 11809 - Floating-Point Numbers
*https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=226&page=show_problem&problem=2909
*题意：给出一个浮点数，求出尾数和阶码所需的最小位数。
*解题思路：开二维数组A[][]和B[][]分别记录对应位数的尾数和阶码的组合时尾数和指数所能表示的最大值，然后打表查找比较。
*对于一个E位二进制数的尾数，它的十进制尾数值p = 1-2^(-M-1), 
*对于一个M位二进制数的阶码，可表示的指数为2^q = 2^[ 2 ^(E-1)],
*然后把这个数转换成对应的以10为底的计数法表示出来，p*2^q=a*10^b，
*两边取对数，得到log10(p)+q*log10(2)=log10(a)+b，令左边为t，
*则 b=t-log10(a)，由于1<=a<10，所以log10(a)<1，b为指数，为正，
*所以b=t/1(自动向下取整），所以a=10^(t-b)，这样打表。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
#define EPS 1e-6

double A[16][64], B[16][64];

int main(){
	for(int M = 0; M <= 9; ++M){
		for(int E = 1; E <= 30; ++E){
			// maxval = (1 - 2^{-M - 1}) \times 2^{2^{E} - 1}
			// log10(maxval) = log10(a) + b, 0 < a < 10, b \in N
			double p = 1 - pow(2, -M - 1);
			double q = pow(2, E) - 1;
			double logsum = log10(p) + log10(2) * q;
			double b = floor(logsum);
			double a = pow(10, logsum - b);
			A[M][E] = a, B[M][E] = b;
		}
	}
	char s[128];
	while(scanf("%s", s) == 1){
		if(strcmp(s, "0e0") == 0){
			break;
		}
		for(int i = 0; s[i]; ++i){
			if(s[i] == 'e'){
				s[i] = ' ';
			}
		}
		double a, b;
		sscanf(s, "%lf %lf", &a, &b);
		for(int M = 0; M <= 9; ++M){
			for(int E = 1; E <= 30; ++E){
				if(fabs(A[M][E] - a) < EPS && fabs(B[M][E] - b) < EPS){
					printf("%d %d\n", M, E);
				}
			}
		}
	}
	return 0;
}