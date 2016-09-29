#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Matrix
{
	int row, col;
	Matrix(int r = 0, int c = 0) : row(r), col(c) {}
	//Matrix() : Matrix(0, 0) {}
} m[26];

int main(int argc, char const *argv[]){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		string name;
		cin >> name;
		int row, col;
		cin >> row >> col;
		m[name[0] - 'A'] = Matrix(row, col);
	}
	string expr;
	while (cin >> expr){
		stack<Matrix> s;
		bool ok = true;
		long long sum = 0;
		int len = expr.length();
		for (int i = 0; i < len; ++i){
			if (isalpha(expr[i])){
				s.push(m[expr[i] - 'A']);
			}else if (expr[i] == ')'){
				Matrix x2 = s.top();
				s.pop();
				Matrix x1 = s.top();
				s.pop();
				if(x1.col != x2.row){
					ok = false;
					break;
				}
				sum += x1.row * x1.col * x2.col;
				s.push(Matrix(x1.row, x2.col));
			}
		}
		if(ok) cout << sum << endl;
		else cout << "error" <<endl;
	}
	return 0;
}