#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sequencestack(int m, int n) {
	//ex: m=5 n=7
	int stack[1010] = { 0 };
	int flag[1010] = { 0 };
	int top = 0;
	int front = 1;
	for (int i = 1; i <= n; i++) {
		flag[i] = i;
	}
	int a[1010];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while (stack[top] != a[1]) {
		top++;
		stack[top] = flag[front];
		front++;
		if (front > n + 1) {
			return false;
		}
		if (top>m) {
			return false;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (stack[top] == a[i]) {
			stack[top] = 0;
			top--;
		}
		else if (stack[top] > a[i]) {
			return false;
		}
		else {
			while (stack[top] != a[i]) {
				top++;
				stack[top] = flag[front];
				front++;
				if (front > n + 1) {
					return false;
				}
				if (top > m) {
					return false;
				}
			}
			i--;
		}
	}
	return true;
}

int main() {
	int m, n, k;
	//m是栈的大小，n是队列的长度，k是要判断的出栈序列的个数
	cin >> m >> n >> k;
	vector<bool> v;
	for (int i = 0; i < k; i++) {
		v.push_back(sequencestack(m, n));
	}
	for (auto i = v.begin(); i != v.end(); i++) {
		if (*i) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	system("pause");
}