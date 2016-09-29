#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, *a, *b;
	int kase = 0;
	while(scanf("%d", &N) != EOF && N != 0){
		printf("Game %d:\n", ++kase);
		a = new int[N];
		b = new int[N];
		for(int i = 0; i < N; ++i){
			scanf("%d", &a[i]);
		}
		while(true){
			int A = 0, B = 0;
			for(int i = 0; i < N; ++i){
				scanf("%d", &b[i]);
				if(a[i] == b[i]) ++A;
			}
			if(b[0] == 0) break;
			for(int d = 1; d <= 9; ++d){
				int c1 = 0, c2 = 0;
				for(int i = 0; i < N; ++i){
					if(a[i] == d) ++c1;
					if(b[i] == d) ++c2;
				}
				B += min(c1, c2);
			}
			printf("    (%d,%d)\n", A, B-A);
		}
	}
	return 0;
}