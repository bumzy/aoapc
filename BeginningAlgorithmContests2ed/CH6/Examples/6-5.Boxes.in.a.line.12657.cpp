#include <iostream>
#include <list>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	int k = 0;
	while(cin >> n >> m) {
	    cout << "Case " << ++k <<": ";
	    list<int> li;
	    map<int, list<int>::iterator> cache;
	    for (int i = 1; i <= n; ++i)
	    {
	    	li.push_back(i);
	    	cache[i] = --li.end();
	    }
	    for (int i = 0; i < m; ++i)
	    {
	    	int op, x, y;
	    	cin >> op;
	    	if (op != 4)
	    	{
	    		cin >> x >> y;
	    		if (op == 1)
	    		{
	    			int tmp = *cache[x];
	    			li.erase(cache[x]);
	    			li.insert(cache[y], tmp);
	    		}else if(op == 2){
	    			int tmp = *cache[x];
	    			li.erase(cache[x]);
	    			li.insert(++cache[y], tmp);
	    		}else if(op == 3){
	    			swap(cache[x], cache[y]);
	    		}
	    	}else{
	    		li.reverse();
	    	}
	    	/**
		    for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
		    {
		    	cout << *it << " ";
		    }
		    cout << endl;
		    **/
	    }
	    long long ans = 0;
	    for (list<int>::iterator it = li.begin(); it != li.end(); ++it, ++it)
	    {
	    	ans += *it;
	    }
	    cout << ans << endl;
	}
	return 0;
}