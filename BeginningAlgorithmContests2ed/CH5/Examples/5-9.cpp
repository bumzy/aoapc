/**
 * UVa1592 - Database
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=835&page=show_problem&problem=4467
 */
#include <cstdio>
#include <string>
#include <map>
#include <utility>
using namespace std;

int n, m;
int database[10010][15];
map<string, int> strToIntMap;
map<pair<int, int>, int> colMap;

int t = 0;
int strToInt(const string &str){
	if(strToIntMap.count(str)) return strToIntMap[str];
	else{
		strToIntMap[str] = t;
		return t++;
	}
}

int main(){
	while(scanf("%d%d", &n, &m) != EOF){
		getchar();
		strToIntMap.clear();
		for(int i = 0; i < n; ++i){
			string sub;
			char entry[128], comma;
			for(int j = 0; j < m-1; ++j){
				scanf("%[^,]%c", entry, &comma);
				database[i][j] = strToInt(string(entry));
			}
			scanf("%[^\n]", entry);
			getchar();
			database[i][m-1] = strToInt(string(entry));
		}
		bool flag = true;
		for(int i = 0; i < m && flag; ++i){
			for(int j = i + 1; j < m && flag; ++j){
				colMap.clear();
				for(int k = 0; k < n && flag; ++k){
					pair<int, int> p = make_pair(database[k][i], database[k][j]);
					if(colMap.count(p)){
						flag = false;
						printf("NO\n");
						printf("%d %d\n", colMap[p]+1, k+1);
						printf("%d %d\n", i+1, j+1);
					}else{
						colMap[p] = k;
					}
				}
			}
		}
		if(flag)
			printf("YES\n");
	}
	return 0;
}