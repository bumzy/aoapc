/**
 * UVa101 - The Blocks Problem
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=835&page=show_problem&problem=37
 */
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 30;
int N;
struct Position {
	int blk, idx;
	Position(int _b = -1,  int _i = -1) : blk(_b), idx(_i) {}
} pos[MAXN];
vector<int> block[MAXN];

void printBlock() {
	for (int i = 0; i < N; ++i) {
		printf("%d:", i);
		for (size_t j = 0; j < block[i].size(); ++j) {
			printf(" %d", block[i][j]);
		}
		printf("\n");
	}
}

void cleanTop(int x) {
	int blk = pos[x].blk;
	int idx = pos[x].idx;
	for (size_t i = idx + 1; i < block[blk].size(); ++i) {
		int t = block[blk][i];
		block[t].push_back(t);
		pos[t] = Position(t, block[t].size() - 1);
	}
	block[blk].resize(idx + 1);
}

void pileOver(int a, int b) {
	int aBlk = pos[a].blk;
	int aIdx = pos[a].idx;
	int bBlk = pos[b].blk;
	for (size_t i = aIdx; i < block[aBlk].size(); ++i) {
		int t = block[aBlk][i];
		block[bBlk].push_back(t);
		pos[t] = Position(bBlk, block[bBlk].size() - 1);
	}
	block[aBlk].resize(aIdx);
}

int main() {
	while (scanf("%d", &N) == 1) {
		for (int i = 0; i < N; ++i) {
			block[i].clear();
			block[i].push_back(i);
			pos[i] = Position(i, 0);
		}
		char op[8], sub[8];
		int a, b;
		for (;;) {
			scanf("%s", op);
			if (strcmp(op, "quit") == 0) {
				printBlock();
				break;
			}
			scanf("%d%s%d", &a, sub, &b);
			if (a == b || pos[a].blk == pos[b].blk)
				continue;
			if (strcmp(op, "move") == 0)
				cleanTop(a);
			if (strcmp(sub, "onto") == 0) {
				cleanTop(b);
			}
			pileOver(a, b);
		}
	}
	return 0;
}