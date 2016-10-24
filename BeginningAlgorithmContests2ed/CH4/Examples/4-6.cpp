#include <cstdio>
#include <cstring>
using namespace std;

const double EPS = 1e-5;
const int MAXLEN = 128;
const int MAXN = 1010;
int n;
struct Student{
	int score[5], cid;
	char sid[MAXLEN], name[MAXLEN];
	bool valid;
} stu[MAXN];

void print_menu(){
	printf("Welcome to Student Performance Management System (SPMS).\n\n");
	printf("1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n\n");
}

void add(){
	char sid[MAXLEN], name[MAXLEN];
	int score[5], cid;
	for(;;){
		printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
		scanf("%s", sid);
		if(strcmp(sid, "0") == 0) return;
		scanf("%d%s%d%d%d%d", &cid, name, &score[0], &score[1], &score[2], &score[3]);
		
		bool exist = false;
		for(int i = 0; i < n; ++i){
			if(stu[i].valid && strcmp(sid, stu[i].sid) == 0) exist = true;
		}
		if(exist){
			printf("Duplicated SID.\n");
		}else{
			strcpy(stu[n].sid, sid);
			stu[n].cid = cid;
			strcpy(stu[n].name, name);
			for(int i = 0; i < 4; ++i){
				stu[n].score[i] = score[i];
				stu[n].score[4] += score[i];
			}
			stu[n++].valid = true;
		}
	}
}

int rank(int q){
	int r = 1;
	for(int i = 0; i < n; ++i){
		if(stu[i].valid && stu[i].score[4] > stu[q].score[4]){
			r++;
		}
	}
	return r;
}

void DQ(bool isq){
	char s[MAXLEN];
	for(;;){
		printf("Please enter SID or name. Enter 0 to finish.\n");
		scanf("%s", s);
		if(strcmp(s, "0") == 0) return;
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			if(stu[i].valid && (strcmp(stu[i].sid, s) == 0 || strcmp(stu[i].name, s) == 0)){
				if(isq){
					printf("%d %s %d %s %d %d %d %d %d %.2lf\n", 
						rank(i), stu[i].sid, stu[i].cid, stu[i].name, 
						stu[i].score[0], stu[i].score[1], stu[i].score[2], 
						stu[i].score[3], stu[i].score[4], (double)stu[i].score[4]/4.0+EPS);
				}else{
					stu[i].valid = false;
					cnt++;
				}
			}
		}
		if(isq == false){
			printf("%d student(s) removed.\n", cnt);
		}
	}
}

void stat(){
	int cid;
	double sum[4] = {0.0};
	int pass[4][2] = {0};
	int cnt[5] = {0};
	int num = 0;
	const char *discipline[] = {"Chinese", "Mathematics", "English", "Programming"};
	printf("Please enter class ID, 0 for the whole statistics.\n");
	scanf("%d", &cid);
	for(int i = 0; i < n; ++i){
		if(stu[i].valid && (stu[i].cid == cid || cid == 0)){
			int passed = 0;
			for(int j = 0; j < 4; ++j){
				sum[j] += stu[i].score[j];
				if(stu[i].score[j] >= 60){
					pass[j][0]++;
					passed++;
				}else{
					pass[j][1]++;
				}
			}
			cnt[passed]++;
			num++;
		}
	}
	for(int i = 4; i > 1; --i){
		cnt[i-1] += cnt[i];
	}
	for(int i = 0; i < 4; ++i){
		printf("%s\nAverage Score: %.2lf\nNumber of passed students: %d\nNumber of failed students: %d\n\n", 
			discipline[i], num == 0 ? 0 : (sum[i] / num + EPS), pass[i][0], pass[i][1]);
	}
	printf("Overall:\nNumber of students who passed all subjects: %d\n", cnt[4]);
	printf("Number of students who passed 3 or more subjects: %d\n", cnt[3]);
	printf("Number of students who passed 2 or more subjects: %d\n", cnt[2]);
	printf("Number of students who passed 1 or more subjects: %d\n", cnt[1]);
	printf("Number of students who failed all subjects: %d\n\n", cnt[0]);
}

int main(){
	for(;;){
		int choice;
		print_menu();
		scanf("%d", &choice);
		if(choice == 0) break;
		else if(choice == 1) add();
		else if(choice == 2) DQ(false);
		else if(choice == 3) DQ(true);
		else if(choice == 4) printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
		else if(choice == 5) stat();
	}
	return 0;
}