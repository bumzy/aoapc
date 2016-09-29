#include <cstdio>
using namespace std;

const int MAXN = 100;
const double weight[4] = {12.01, 1.008, 16.00, 14.01};
int T;
char str[MAXN];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%s", str);
		int i = 0, num = 0;
		double sum = 0, pre = 0;
		while(str[i] != '\0'){
			if(str[i] >= '0' && str[i] <= '9'){
				num = num*10 + str[i] - '0';
			}else{
				if(num == 0) num = 1;
				sum += pre * num;
				num = 0;
				if(str[i] == 'C'){
					pre = weight[0];
				}else if(str[i] == 'H'){
					pre = weight[1];
				}else if(str[i] == 'O'){
					pre = weight[2];
				}else if(str[i] == 'N'){
					pre = weight[3];
				}
			}
			++i;
		}
		if(num == 0) num = 1;
		sum += pre * num;
		printf("%0.3lf\n", sum);
	}
	return 0;
}