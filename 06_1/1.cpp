#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int>result1;
vector<int>result2;
int find(vector<vector<int>>v, int tip, vector<int>& tag);
int Filter(vector<vector<int>>v, int tip, vector<int>& tag);

//广度优先
queue<int>q;
vector<int> tag2(20);
void BFS(vector<vector<int>>v) {
	//vector<int> tag(v.size());
	//queue<int> q;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].size() == 0) {
			tag2[i] = 1;
			result2.push_back(i);
		}
		else {
			if (tag2[i] == 0) {
				q.push(i);
				tag2[i] = 1;
			}
			Filter(v, i, tag2);
		}
		if (!result2.empty()) {
			cout << "{";
			for (auto k = result2.begin(); k != result2.end(); ++k) {
				cout << " " << *k;
			}
			cout << " }" << endl;
		}
		result2.clear();
	}
}

int Filter(vector<vector<int>>v, int tip, vector<int>& tag) {
	for (int i = 0; i < v[tip].size(); i++) {
		if (tag[v[tip][i]] == 0) {
			q.push(v[tip][i]);
			tag[v[tip][i]] = 1;

		}
	}
	if (!q.empty()) {
		result2.push_back(q.front());
		q.pop();
		for (int i = 0; i < q.size(); i++) {
			Filter(v, q.front(), tag);
		}
	}
	return 0;
}

//深度优先
vector<int> tag1(20);
void DFS(vector<vector<int>>v) {

	for (int i = 0; i < v.size(); i++) {
		if (v[i].size() == 0) {
			result1.push_back(i);
			tag1[i] = 1;
			/*result1.push_back(-1);*/
		}
		else {
			if (tag1[i] == 0) {
				result1.push_back(i);
				tag1[i] = 1;
				find(v, i, tag1);
			}
		}
		if (!result1.empty()) {
			cout << "{";
			for (auto k = result1.begin(); k != result1.end(); ++k) {
				cout << " " << *k;
			}
			cout << " }" << endl;
		}
		result1.clear();
	}
}
int find(vector<vector<int>>v, int tip, vector<int>& tag) {
	for (int i = 0; i < v[tip].size(); i++) {
		//tag==0没被搜过
		if (tag[v[tip][i]] == 0) {
			result1.push_back(v[tip][i]);
			tag[v[tip][i]] = 1;
			find(v, v[tip][i], tag);
		}
	}
	return 0;
}

int main() {
	int vertex, side;//点 边
	cin >> vertex >> side;
	vector<vector<int>>v(vertex);
	for (int i = 0; i < side; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}
	for (int i = 0; i < vertex; i++) {
		sort(v[i].begin(), v[i].end());
	}
	//BFS(v);
	DFS(v);
	BFS(v);
}