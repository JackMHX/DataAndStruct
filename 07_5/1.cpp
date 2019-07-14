//错的还没想出来

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


typedef struct node
{
	int x;
	int y;
	int tag = 0;
	bool isbank = false;
}node;

struct path
{
	int id;
	int distance;
};

int jumpdistance;
int jumptimes = 0;

vector<path> q;
vector<node> g;
vector<vector<path>>t;


int getdistance(int a, int b,int x,int y) {
	return (a - x)*(a - x) + (b - y)*(b - y);
}

bool canjump(int a, int b, int x, int y) {
	if (jumptimes == 0 && getdistance(a, b, x, y)<= (7.5 + jumpdistance)*(7.5 + jumpdistance)) {
		jumptimes = -1;
		return true;
	}
	else if (jumptimes != 0 && getdistance(a, b, x, y) <= jumpdistance * jumpdistance) {
		return true;
	}
	else return false;
	
}


void cleanqueue(vector<path> &q) {
	while (!q.empty()) {
		q.pop_back();
	}
}

int Jump(int num) {
	if (g[num].isbank) {
		//上岸了
		t.push_back(q);
		return 1;
	}
	for (int i = 0; i < g.size(); i++) {
		if (g[i].tag == 0 && 
			canjump(g[i].x,g[i].y,g[num].x,g[num].y))
		{
			g[i].tag = 1;
			int d;
			d = sqrt(getdistance(g[i].x, g[i].y, g[num].x, g[num].y));
			path p;
			p.id = i;
			p.distance = d;
			q.push_back(p);
			Jump(i);
		}
	}
	//循环结束如果没地方跳，那么就要返回到上一个节点
	if (!q.empty()) { q.pop_back(); }
	return 0;
}

void getbankandstart() {
	node k;
	k.x = 0;
	k.y = 0;
	k.tag = 1;
	g.push_back(k);
	for (int i = -49; i <= 50; i++) {
		node p;
		p.x = -49;
		p.y = i;
		p.isbank = true;
		g.push_back(p);
	}
	for (int i = -49; i <= 50; i++) {
		node p;
		p.x = i;
		p.y = -49;
		p.isbank = true;
		g.push_back(p);
	}
	for (int i = -49; i <= 50; i++) {
		node p;
		p.x = 50;
		p.y = i;
		p.isbank = true;
		g.push_back(p);
	}
	for (int i = -49; i <= 50; i++) {
		node p;
		p.x = i;
		p.y = 50;
		p.isbank = true;
		g.push_back(p);
	}
}




int main()
{
	int n, d;//能踩的鳄鱼数量 一次能跳的距离
	cin >> n >> d;
	jumpdistance = d;
	getbankandstart();
	for (int i = 0; i < n; i++) {
		node p;
		cin >> p.x >> p.y;
		g.push_back(p);
	}
	Jump(0);
	int num=0;
	int min=1000000;
	vector<int> alldis(t.size());
	if (t.empty()) { cout << 0; }
	//先算出所有出路的总距离，然后找到距离最小的
	else {
		int sum = 0;
		for (int i = 0; i < t.size(); i++) {
			for (int j = 0; j < t[i].size(); j++) {
				sum = sum + t[i][j].distance;
			}
			alldis[i] = sum;
			sum = 0;
		}
		for (int i = 0; i < alldis.size(); i++) {
			if (alldis[i] < min) {
				num = i;
				min = alldis[i];
			}
			if (alldis[i] == min) {
				num = t[i][0].distance < t[num][0].distance ? i : num;
			}
		}
		//t[i]是最短路径
		for (int i = 0; i < t[num].size()-1; i++) {
			cout << g[t[num][i].id].x <<" "<< g[t[num][i].id].y << endl;
		}
		/*cout << endl;
		for (int i = 0; i < t[0].size() - 1; i++) {
			cout << g[t[num][i].id].x << " " << g[t[num][i].id].y << endl;
		}
		for (int i = 0; i < t[1].size() - 1; i++) {
			cout << g[t[num][i].id].x << " " << g[t[num][i].id].y << endl;
		}*/
		
		
		/*int sum = 0;
		for (int i = 0; i < t.size(); i++) {
			for (int j = 0; j < t[i].size(); j++) {
				if (t[i][j].distance < min) {
					min = t[i][j].distance;
					num = i;
				}
				if (t[i][j].distance == min) {
					num = t[i][0].distance < t[num][0].distance ? i : num;
				}
			}
			sum = 0;
		}
		for (int i = 0; i < t[num].size(); i++) {

		}*/
	}

}
