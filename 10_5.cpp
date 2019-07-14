#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int num_problem = 0;
vector<int> prob;//每题的满分是多少

typedef struct problem {
	bool sub = false;//是否提交
	bool pass = false;//是否编译通过
	bool ac = false;//是否满分
	int score = 0;
	
}Problem;

struct student
{
	int id;
	Problem p[6];
	int pass=0;//编译通过
	int sum_score = 0;//总分
	int AC = 0;//AC的题的数量
	int submis = 0;//提交数
	void getsum_score();
	void getinf(int _id, int _p_num, int score);
	student(){}
	
};
//bool sub = false;//是否提交
//bool pass = false;//是否编译通过
//bool ac = false;//是否满分
void student::getinf(int _id,int _p_num,int _score){
	id = _id;
	if (_score == -1) {
		/*	有一种情况是，
			之前已经提交过通过编译器的代码了，
			然后他又提交了不通过编译器的代码
		*/
		if (p[_p_num].score > 0) {}
		else {
			p[_p_num].pass = false;//编译没有通过
			p[_p_num].sub = true;//提交了
			submis++;
			p[_p_num].score = 0;
		}
	}
	else {
		p[_p_num].pass = true;//编译通过
		p[_p_num].sub = true;//提交了
		submis++;
		pass++;
		if (_score > p[_p_num].score) {
			p[_p_num].score = _score;
			if (_score == prob[_p_num]) {
				p[_p_num].ac = true;
				AC++;
			}
		}
		
		
	}
}
void student::getsum_score() {
	for (int i = 0; i < 6; i++) {
		if (p[i].score >= 0) {
			sum_score += p[i].score;
		}
	}
}

bool cmp(student a, student b) {
	if (a.sum_score > b.sum_score)
		return true;
	else if (a.sum_score == b.sum_score) {
		if (a.AC > b.AC)
			return true;
		else if (a.AC == b.AC) {
			if(a.id<b.id)
				return true;
			else 
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

int main() {
	int n, m, k;//总人数，题目数量，总提交数
	cin >> n >> m >> k;
	num_problem = m;
	prob.resize(num_problem+1);
	vector<student>s(n+1);//人数
	for (int i = 1; i <= m; i++) {
		cin >> prob[i];
	}
	for (int i = 0; i < k; i++) {
		int id, p_num, score;//编号，题号，分数
		cin >> id >> p_num >> score;
		s[id].getinf(id, p_num, score);
	}
	//统计总分
	for (int i = 1; i < s.size(); i++) {
		s[i].getsum_score();
	}
	sort(s.begin(), s.end(), cmp);
	int rank = 0;
	int pastscore = -2;
	int num = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i].pass != 0 && s[i].submis!=0) {
			if (s[i].sum_score == pastscore) {
				pastscore = s[i].sum_score;
				num++;
			}
			else {
				num++;
				rank = num;
				pastscore = s[i].sum_score;
			}
			cout << rank << " ";
			printf("%05d %d ", s[i].id,s[i].sum_score);
			for (int j = 1; j <= m; j++) {
				if (j == m) {
					if (s[i].p[j].sub == true)
						printf("%d", s[i].p[j].score);
					else
						printf("-");
				}
				else {
					if (s[i].p[j].sub == true)
						printf("%d ", s[i].p[j].score);
					else
						printf("- ");
				}
			}
			cout << endl;
		}
	}
	system("pause");
}