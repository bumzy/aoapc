/*
*思路：分别将1-6面朝上，再以水平面垂直方向为轴，旋转4次
*/
#include <cstdio>
using namespace std;

const int start[6][6] = {
	1, 2, 3, 4, 5, 6,
	2, 6, 3, 4, 1, 5,
	3, 2, 6, 1, 5, 4,
	4, 2, 1, 6, 5, 3,
	5, 1, 3, 4, 6, 2,
	6, 5, 3, 4, 2, 1
};
const int rotat[4][6] = {
	1, 2, 3, 4, 5, 6,
	1, 3, 5, 2, 4, 6,
	1, 4, 2, 5, 3, 6,
	1, 5, 4, 3, 2, 6
};
struct Cube{
	char p[6];
}a, b, t1, t2;
char s[24];

bool cmp(const Cube &a, const Cube &b){
	for(int i = 0; i < 6; ++i){
		if(a.p[i] != b.p[i])
			return false;
	}
	return true;
}

Cube change(const Cube &a, const int arr[6]){
	Cube ret;
	for(int j = 0; j < 6; ++j){
		ret.p[j] = a.p[arr[j] - 1];
	}
	return ret;
}

int main(){
	while(scanf("%s", s) == 1){
		for(int i = 0; i < 6; ++i){
			a.p[i] = s[i], b.p[i] = s[i+6];
		}
		bool flag = false;
		for(int i = 0; i < 6 && flag == false; ++i){
			t1 = change(a, start[i]);
			for(int k = 0; k < 4 && flag == false; ++k){
				t2 = change(t1, rotat[k]);
				if(cmp(t2, b)){
					flag = true;
				}
			}
		}
		printf("%s\n", flag ? "TRUE" : "FALSE");
	}
	return 0;
}