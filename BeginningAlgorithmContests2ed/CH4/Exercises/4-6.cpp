#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

map<char, string> table;
map<string, set<string> > context;

int main(){
	string letter, morse;
	while(cin >> letter){
		table.clear(), context.clear();
		cin >> morse;
		table[letter[0]] = morse;
		while(cin >> letter && letter != "*"){
			cin >> morse;
			table[letter[0]] = morse;
		}
		string word, morseWord;
		while(cin >> word && word != "*"){
			morseWord.clear();
			for(size_t i = 0; i < word.length(); ++i){
				morseWord += table[word[i]];
			}
			//cout << word << " " << morseWord << endl;
			context[morseWord].insert(word);
		}
		while(cin >> morseWord && morseWord != "*"){
			if(context.find(morseWord) != context.end()){
				cout << *context[morseWord].begin();
				if(context[morseWord].size() > 1) cout << "!";
				cout << endl;
			}else{
				string ans;
				int min = 0x3fffffff;
				map<string, set<string> >::iterator miter;
				for(miter = context.begin(); miter != context.end(); ++miter){
					string str = miter->first;
					if(str.find(morseWord) == 0 || morseWord.find(str) == 0){
						if(min > abs((int)str.length() - (int)morseWord.length())){
							min = abs((int)str.length() - (int)morseWord.length());
							ans = *miter->second.begin();
						}
					}
				}
				cout << ans << "?" << endl;
			}
		}
	}
	return 0;
}