#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>

using namespace std;

vector<int> inorder;//中序
vector<int> preorder;//前序
vector<int> postorder;//后序

stack<int> p;
//pop inorder
//push preorder

void post(int root, int start, int end) {
	if (start > end) { return; }
	int i = start;
	while (i < end && inorder[i] != preorder[root]) { i++; }
	post(root + 1, start, i - 1);
	post(root + 1 + i - start, i + 1, end);
	postorder.push_back(preorder[root]);
}


int main() {
	int n;
	cin >> n;
	/*pre.resize(n);
	post.resize(n);*/
	for (int i = 0; i <2*n; i++) {
		string s;
		cin >> s;
		if (s == "Push") {
			int data;
			cin >> data;
			preorder.push_back(data);
			p.push(data);
		}
		else {
			int data;
			data = p.top();
			p.pop();
			inorder.push_back(data);
		}
	}
	post(0, 0, n - 1);
	for (auto i = postorder.begin(); i < postorder.end(); i++) {
		if (i != postorder.end()-1) {
			cout << *i << " ";
		}
		else {
			cout << *i;
		}
	}
	system("pause");
}