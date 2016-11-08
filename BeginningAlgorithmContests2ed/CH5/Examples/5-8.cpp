/**
 * UVa400 - Unix ls
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=835&page=show_problem&problem=341
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXCOL = 60;
const int MAXN = 100 + 10;
int N, M = 0;
string filename[MAXN];

void print(const string&s, int len, char extra){
	cout << s;
	for(size_t i = 0; i < len - s.length(); ++i)
		cout << extra;
}

int main(){
	while(cin >> N){
		M = 0;
		for(int i = 0; i < N; ++i){
			cin >> filename[i];
			M = max(M, (int)filename[i].length());
		}
		int cols = (MAXCOL - M) / (M + 2) + 1;
		int rows = (N - 1) / cols + 1;
		sort(filename, filename + N);
		print("", 60, '-');
		cout << "\n";
		for(int r = 0; r < rows; ++r){
			for(int c = 0; c < cols; ++c){
				int idx = c * rows + r;
				if(idx < N)
					print(filename[idx], c == cols - 1 ? M : M+2, ' ');
			}
			cout << "\n";
		}
	}
	return 0;
}