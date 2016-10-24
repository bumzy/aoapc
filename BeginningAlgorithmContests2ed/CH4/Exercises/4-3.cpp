#include <cstdio>
#include <cstring>
using namespace std;

char board[10][10], cur[4], op[8];
int T;
struct Point{
	int x, y;
} point[128];
int n;

const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

void readBoard(){
	memset(board, 0, sizeof(board));
	for(int i = 1; i <= 8; ++i){
		scanf("%s", &board[i][1]);
	}
}

void printBoard(){
	for(int i = 1; i <= 8; ++i){
		printf("%s\n", &board[i][1]);
	}
	if(T) printf("\n");
}

char opponent(char c){
	return c == 'B' ? 'W' : 'B';
}

int validPos(int x, int y){
	return 1 <= x && x <= 8 && 1 <= y && y <= 8;
}

void creatList(){
	n = 0;
	for(int x = 1; x <= 8; ++x){
		for(int y = 1; y <= 8; ++y){
			if(board[x][y] == '-'){
				for(int i = 0; i < 8; ++i){
					int tx = x + dx[i], ty = y + dy[i];
					int flag = 0;
					while(validPos(tx, ty) && board[tx][ty] == opponent(cur[0])){
						tx += dx[i], ty += dy[i];
						flag = 1;
					}
					if(flag && validPos(tx, ty) && board[tx][ty] == cur[0]){
						point[n].x = x, point[n++].y = y;
						break;
					}
				}
			}
		}
	}
}

void printList(){
	creatList();
	if(n){
		for(int i = 0; i < n; ++i){
			if(i > 0) printf(" ");
			printf("(%d,%d)", point[i].x, point[i].y);
		}
		printf("\n");
	}else{
		printf("No legal move.\n");
	}
}

void makeMove(int x, int y){
	creatList();
	if(n == 0){
		cur[0] = opponent(cur[0]);
	}
	board[x][y] = cur[0];
	for(int i = 0; i < 8; ++i){
		int tx = x + dx[i], ty = y + dy[i];
		while(validPos(tx, ty) && board[tx][ty] == opponent(cur[0])){
			tx += dx[i], ty += dy[i];
		}
		if(validPos(tx, ty) && board[tx][ty] == cur[0]){
			tx -= dx[i], ty -= dy[i];
			while(validPos(tx, ty) && board[tx][ty] == opponent(cur[0])){
				board[tx][ty] = cur[0];
				tx -= dx[i], ty -= dy[i];
			}
		}
	}
	cur[0] = opponent(cur[0]);
	int cntB = 0, cntW = 0;
	for(int x = 1; x <= 8; ++x){
		for(int y = 1; y <= 8; ++y){
			if(board[x][y] == 'B')
				cntB++;
			else if(board[x][y] == 'W')
				cntW++;
		}
	}
	printf("Black - %2d White - %2d\n", cntB, cntW);
}

int main(){
	scanf("%d", &T);
	while(T--){
		readBoard();
		scanf("%s", cur);
		while(scanf("%s", op) == 1){
			if(op[0] == 'L'){
				printList();
			}else if(op[0] == 'M'){
				makeMove(op[1] - '0', op[2] - '0');
			}else if(op[0] == 'Q'){
				printBoard();
				break;
			}
		}
	}
	return 0;
}