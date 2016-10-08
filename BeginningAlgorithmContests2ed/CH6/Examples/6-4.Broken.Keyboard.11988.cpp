#include <string>
#include <list>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	while(cin >> s) {
	    list<char> result;
	    list<char>::iterator it = result.end();
	    for (int i = 0; i < s.length(); ++i)
	    {
	    	if (s[i] == '[')
	    	{
	    		it = result.begin();
	    	}else if (s[i] == ']'){
	    		it = result.end();
	    	}else{
	    		result.insert(it, s[i]);
	    	}
	    }
	    for (list<char>::iterator it = result.begin(); it != result.end(); ++it)
	    {
	    	cout << *it;
	    }
	    cout << endl;
	}
	return 0;
}