#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define inf 100000
#define MAXSIZE 105

int g[MAXSIZE][MAXSIZE];
int inDegree[MAXSIZE];
int earliest[MAXSIZE];
int n_v;
int ans[MAXSIZE];
int topologicalSort() {
	int num = 0;
	queue<int> q;
	for (int i = 0; i < n_v; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			ans[i] = 0;
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < n_v; i++) {
			int v;
			if (g[u][i] != 0 && g[u][i] != inf) {
				v = i;
				inDegree[v]--;
				if (ans[u] + g[u][v] > ans[v]) {
					ans[v] = ans[u] + g[u][v];
				}
				if (inDegree[v] == 0) {
					q.push(v);
				}
			}
		}
		num++;
	}
	if (num != n_v)
		return false;
	else
		return true;
}

int main() {
	int n, m;
	cin >> n >> m;//活动检查点数目，活动数目
	n_v = n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				g[i][j] = 0;
			else
				g[i][j] = inf;
		}
	}
	int n1, n2, tim;
	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2 >> tim;
		g[n1][n2] = tim;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (g[i][j] != 0 && g[i][j] != inf)
				inDegree[j]++;
		}
	}
	int maxnum = 0;
	if (!topologicalSort()) {
		cout << "Impossible" << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (ans[i] > maxnum)
				maxnum = ans[i];
		}
		cout << maxnum;
	}
	system("pause");
}