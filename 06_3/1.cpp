#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> q;

int BFS(vector<vector<int>> v, int num, vector<int> tag);
int main() {
	int vertex, side;
	cin >> vertex >> side;
	vector<vector<int>> v(vertex + 1);
	vector<int> tag(vertex + 1);

	for (int i = 0; i < side; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}
	for (int i = 1; i <= vertex; i++) {
		int count = BFS(v, i, tag);
		double result = (count*1.0 / vertex) * 100;
		cout << i << ": ";
		printf("%.2lf", result);
		cout << "%" << endl;
		while (!q.empty())
		{
			q.pop();
		}
	}
	system("pause");
}


int level, last, tail;

void enqueque(int num, queue<int>& q) {
	q.push(num);
}
int dequeue(queue<int>& q) {
	int front = q.front();

	q.pop();
	return front;
}
int cmt;
int BFS(vector<vector<int>> v, int num, vector<int> tag) {
	tag[num] = 1;
	cmt = 1;
	level = 0;
	last = num;
	tail = num;
	//入列
	enqueque(num, q);
	while (!q.empty())
	{
		//得到出列的值
		num = dequeue(q);
		for (int i = 0; i < v[num].size(); i++) {
			if (tag[v[num][i]] == 0) {
				tag[v[num][i]] = 1;
				enqueque(v[num][i], q);
				cmt++;
				tail = v[num][i];
			}
		}
		if (num == last) {
			level++;
			last = tail;
		}
		if (level == 6) { break; }
	}

	return cmt;
}
