#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Position
{
	int x;
	int y;
	int bank = 0;//0不是岸；1是岸
}position;

int Jump(int a, int b, int jumpdistance);
int visit(int p);
vector<position> g;
int distancesquare(int a, int b, int x, int y);
int jumptimes = 0;
int jumpdistance;
vector<int>tag;
int answer = 0;

int main() {
	int n;//number of crocodiles
	int d;//maximum distance james can jump in one time
	cin >> n >> d;
	jumpdistance = d;
	//position of bank
	for (int i = -49; i <= 50; i++) {
		position p;
		p.x = i;
		p.y = 50;
		p.bank = 1;
		g.push_back(p);
		tag.push_back(0);
	}
	for (int i = -49; i <= 50; i++) {
		position p;
		p.x = 50;
		p.y = i;
		p.bank = 1;
		g.push_back(p);
		tag.push_back(0);
	}
	for (int i = -49; i <= 50; i++) {
		position p;
		p.x = i;
		p.y = -49;
		p.bank = 1;
		g.push_back(p);
		tag.push_back(0);
	}
	for (int i = -49; i <= 50; i++) {
		position p;
		p.x = -49;
		p.y = i;
		p.bank = 1;
		g.push_back(p);
		tag.push_back(0);
	}
	for (int i = 0; i < n; i++) {
		position p;
		cin >> p.x >> p.y;
		g.push_back(p);
		tag.push_back(0);
	}

	int result = Jump(0, 0, jumpdistance);
	if (result == 1) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	system("pause");
}

int distancesquare(int a, int b,int x,int y) {
	//与坐标的距离
	return (a-x) * (a-x) + (b-y) * (b-y);
}

int Jump(int a,int b,int jumpdistance) {
	if (jumptimes != 0) {
		for (int i = 0; i < g.size(); i++) {
			if (distancesquare(a, b, g[i].x, g[i].y)
				<= (jumpdistance*jumpdistance) && tag[i] == 0) {
				//跳上去
				if (visit(i) == 1) {
					return 1;
				}
			}

		}
	}
	//第0跳要加上岛的半径
	else {
		jumptimes = -1;
		for (int i = 0; i < g.size(); i++) {
			if (distancesquare(a, b, g[i].x, g[i].y)
				<= (7.5 + jumpdistance)*(7.5 + jumpdistance) && tag[i]==0) {
				//跳上去
				if (visit(i) == 1) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int visit(int p) {
	tag[p] = 1;
	if (g[p].bank == 1) {
		//上岸了
		return 1;
	}
	else {
		return Jump(g[p].x, g[p].y, jumpdistance);
	}
	return 0;
}