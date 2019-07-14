#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
#define maxsize 100000
vector<int> g[maxsize];//邻接表
//int b[maxsize] = { 0 };
int a[maxsize] = { 0 };
int indegree[maxsize];//入度的数量

int main() {
	int n;
	cin >> n;//表长
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		a[i] = num;
	}
	//先建邻接表
	for (int i = 0; i < n; i++) {
		int p = a[i] % n;
		while (a[i] > 0 && p != i) {
			indegree[a[i]]++;
			g[a[p]].push_back(a[i]);
			p = (p + 1) % n;
		}
	}
	priority_queue<int,vector<int>,greater<int>> q;
	int tag = 0;
	for (int i = 0; i < n; i++) {
		if (indegree[a[i]] == 0 && a[i] >= 0) {
			q.push(a[i]);
		}
	}
	while (!q.empty()) {
		int u = q.top();
		if (tag == 0)
			cout << u;
		else
			cout << " " << u;
		q.pop();
		tag = -1;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			indegree[v]--;
			if (indegree[v] == 0) {
				q.push(v);
			}
		}
	}
	system("pause");
}