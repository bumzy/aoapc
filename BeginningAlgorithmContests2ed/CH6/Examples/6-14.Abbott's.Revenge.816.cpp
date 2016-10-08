#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

struct Node{
	int r, c, dir;
	Node(int row=0, int col=0, int directory=0):r(row), c(col), dir(directory){}
};

const int maxn = 10;
int r0, c0, dir;
int r1, c1;
int r2, c2;
bool has_edge[maxn][maxn][4][3];
int d[maxn][maxn][4];
Node p[maxn][maxn][4];
int dr[] = {-1, 0, 1, 0};
int dc[] = { 0, 1, 0, -1};

const char *dirs = "NESW";
const char *turns = "FLR";
int dir_id(char c){
	return strchr(dirs, c) - dirs;
}
int turn_id(char c){
	return strchr(turns, c) - turns;
}

Node walk(const Node &u, int turn){
	int dir = u.dir;
	if(turn == 1) dir = (dir + 3) % 4;
	else if(turn == 2) dir = (dir + 1) % 4;
	return Node(u.r + dr[dir], u.c + dc[dir], dir);
}

bool inside(int r, int c){
	return r >= 0 && r <= 9 && c >=0 && c <= 9;
}
bool readCase(){
	char s[100], s2[100];
	if(scanf("%s%d%d%s%d%d", s, &r0, &c0, s2, &r2, &c2) != 6){
		return false;
	}
	printf("%s\n", s);
	dir = dir_id(s2[0]);
	r1 = r0 + dr[dir];
	c1 = c0 + dc[dir];
	memset(has_edge, 0, sizeof(has_edge));
	int r, c;
	while(true){
		scanf("%d", &r);
		if(r == 0){
			break;
		}
		scanf("%d", &c);
		while(scanf("%s", s) == 1){
			if(s[0] == '*'){
				break;
			}
			int dir = dir_id(s[0]);
			int len = strlen(s);
			for(int i = 1; i < len; ++i){
				int turn = turn_id(s[i]);
				has_edge[r][c][dir][turn] = true;
			}
		}
	}
	return true;
}

void print_ans(Node u){
	vector<Node> nodes;
	for(;;){
		nodes.push_back(u);
		if(d[u.r][u.c][u.dir] == 0) break;
		u = p[u.r][u.c][u.dir];
	}
	nodes.push_back(Node(r0, c0, dir));
	int cnt = 0;
	for(int i = nodes.size() - 1; i >= 0; --i){
		if(cnt % 10 == 0) printf(" ");
		printf(" (%d,%d)", nodes[i].r, nodes[i].c);
		if(++cnt % 10 == 0) printf("\n");
	}
	if(nodes.size() % 10 != 0) printf("\n");
}

void solve(){
	queue<Node> q;
	memset(d, -1, sizeof(d));
	Node u(r1, c1, dir);
	d[u.r][u.c][u.dir] = 0;
	q.push(u);
	while(!q.empty()){
		Node u = q.front();
		q.pop();
		if(u.r == r2 && u.c == c2){
			print_ans(u); return;
		}
		for(int i = 0; i < 3; ++i){
			Node v = walk(u, i);
			if(has_edge[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir] < 0){
				d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
				p[v.r][v.c][v.dir] = u;
				q.push(v);
			}
		}
	}
	printf("  No Solution Possible\n");
}

int main(int argc, char const *argv[]){
	while(readCase()){
		solve();
	}
	return 0;
}