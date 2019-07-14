#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int mp[101][101];
const int INF = 10000000;
int n, m;

void Initialize() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) { mp[i][j] = INF; }
		}
	}
	//连接顶点,写入权值
	for (int i = 0; i < m; i++) {
		int v1, v2, d;
		cin >> v1 >> v2 >> d;
		mp[v1][v2] = d;
		mp[v2][v1] = d;
	}
	//floyd
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
			}
		}
	}
}

int main() {
	int vertex, side;
	cin >> vertex >> side;
	n = vertex;
	m = side;
	//初始化图
	Initialize();
	int nn = 0, minn = INF;
	int flag = 1;
	for (int i = 1; i <= n && flag; i++) {
		int tmp = 0;
		for (int j = 1; j <= n && flag; j++) {
			if (mp[i][j] == INF) { flag = 0; break; }
			if (i != j)tmp = max(tmp, mp[i][j]);
		}
		if (flag && tmp<minn ) {
			nn = i; 
			minn = tmp;
		}
	}
	if (flag)cout << nn << " " << minn << endl;
	else cout << 0 << endl;
}