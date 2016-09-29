#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>
using namespace std;

string repr(string s){
	for (int i = 0; i < s.size(); ++i)
	{
		s[i] = tolower(s[i]);
	}
	sort(s.begin(), s.end());
	return s;
}

int main(){
	map<string, int> cnt;
	vector<string> dic;
	string s;
	while(cin >> s){
		if(s == "#") break;
		dic.push_back(s);
		string r = repr(s);
		if(!cnt.count(r)) cnt[r] = 0;
		++cnt[r];
	}
	vector<string> ans;
	for(int i = 0; i < dic.size(); ++i){
		if(cnt[repr(dic[i])] == 1) ans.push_back(dic[i]);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i){
		cout << ans[i] << endl;
	}
	return 0;
}