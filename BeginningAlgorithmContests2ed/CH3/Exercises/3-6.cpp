#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 15;
char matrix[MAXN][MAXN] = {0};
int Index[MAXN][MAXN] = {0};
bool isOutput[MAXN][MAXN] = {false};

int main(){
	int r, c, idx = 0;
	while(scanf("%d", &r) == 1 && r != 0){
		memset(isOutput, 0, sizeof(isOutput));
		memset(Index, 0, sizeof(Index));
		scanf("%d", &c);
		for(int i = 0; i < r; ++i){
			getchar();
			for(int j = 0; j < c; ++j){
				matrix[i][j] = getchar();
			}
		}
		int cnt = 0;
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				if(matrix[i][j] != '*' && (i - 1 < 0 || j - 1 < 0 || matrix[i-1][j] == '*' || matrix[i][j-1] == '*')){
					Index[i][j] = ++cnt;
				}
			}
		}
		if(idx > 0) printf("\n");
		printf("puzzle #%d:\n", ++idx);
		printf("Across\n");
		for(int i = 0; i < r; ++i){
			bool start = false;
			for(int j = 0; j < c; ++j){
				if(start == false && Index[i][j] != 0){
					start = true;
					printf("%3d.", Index[i][j]);
					printf("%c", matrix[i][j]);
				}else if(start == true && matrix[i][j] != '*'){
					printf("%c", matrix[i][j]);
				}
				if(start == true && (matrix[i][j] == '*' || j == c-1)){
					start = false;
					printf("\n");
				}
			}
		}
		printf("Down\n");
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				if(isOutput[i][j] == true || Index[i][j] == 0) continue;
				int k = i;
				bool start = false;
				while(k < r && matrix[k][j] != '*'){
					if(start == false){
						start = true;
						printf("%3d.", Index[k][j]);
						printf("%c", matrix[k][j]);
					}else{
						printf("%c", matrix[k][j]);
					}
					isOutput[k][j] = true;
					++k;
				}
				if(start == true){
					printf("\n");
				}
			}
		}
	}
	return 0;
}