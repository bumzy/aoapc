/**
 * UVa1593 - Alignment of Code
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=836&page=show_problem&problem=4468
 */
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

string word[1010][100];
int maxLen[100] = {0}, numWord[1010] = {0};

void print(const string& s, int len, char ch){
	cout << s;
	for(int i = 0; i < len - (int)s.length(); ++i)
		cout << ch;
}

int main(){
	int i = 0, j = 0, n = 0;
	string str, w;
	while(getline(cin, str)){
		stringstream ss(str);
		j = 0;
		while(ss >> w){
			word[i][j] = w;
			maxLen[j] = max((int)w.length(), maxLen[j]);
			++j;
		}
		numWord[i] = j;
		++i;
	}
	n = i;
	for(i = 0; i < n; ++i){
		for(j = 0; j < numWord[i]; ++j){
			if(j < numWord[i] - 1)
				print(word[i][j], maxLen[j] + 1, ' ');
			else
				cout << word[i][j] << "\n";
		}
	}
	return 0;
}