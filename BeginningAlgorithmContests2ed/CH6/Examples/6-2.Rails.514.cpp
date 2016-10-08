#include <iostream>
#include <stack>
#define MAXN 1000 + 10

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n) {
		if(n == 0){
			break;
		}
	    int x;
	    stack<int> s;
	    int b[MAXN];
	    for (;;)
	    {
		    for(int j = 1; j <= n; ++j){
		    	cin >> x;
		    	if(x == 0){
		    		cout << endl;
		    		break;
		    	}
		    	b[j] = x;
		    }
		    if(x == 0) break;
		    int A = 1, B = 1;
		    bool ok = true;
		    while(B <= n){
		    	if(A == b[B]){
		    		++A;
		    		++B;
		    	}else if(!s.empty() && s.top() == b[B]){
		    		s.pop();
		    		++B;
		    	}else if(A <= n){
		    		s.push(A);
		    		++A;
		    	}else{
		    		ok = false;
		    		break;
		    	}
		    }
		    cout << (ok ? "Yes" : "No") << endl;
	    }
	}
	return 0;
}