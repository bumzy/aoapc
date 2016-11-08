/**
 * UVa10815 - Andy's First Dictionary
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=835&page=show_problem&problem=1756
 */
#include <iostream>
#include <string>
#include <set>
#include <cctype>
using namespace std;

set<string> dict;

int main() {
	string s;
	while (cin >> s) {
		size_t pos = 0, len = 0;
		for (size_t i = 0; i < s.length(); ++i) {
			s[i] = tolower(s[i]);
			if (!isalpha(s[i])) {
				len = i - pos;
				if (len)
					dict.insert(s.substr(pos, len));
				pos = i + 1;
			}
		}
		if (pos < s.length())
			dict.insert(s.substr(pos));
	}
	for (set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}