#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define null -1
typedef struct node* tree;

struct node
{
	int index;
	int left;
	int right;
}treenode[10];


int buildtree(tree T) {
	//建树并找到根节点的编号
	int n;
	cin >> n;
	tree t = T;
	vector<int> check(n);
	int root = -1;
	for (int i = 0; i < n; i++) {
		char cl, cr;
		cin >> cl >> cr;
		treenode[i].index = i;
		if (cl != '-') {
			t->left = cl - '0';
			check[t->left] = 1;
			
		}
		else {
			t->left = null;
		}
		if (cr != '-') {
			t->right = cr - '0';
			check[t->right] = 1;
		}
		else {
			t->right = null;
		}
		t++;
		
	}
	int i;
	for (i = 0; i < n; i++) {
		if (check[i] == 0) {
			root = i;
			break;
		}
	}
	return root;

}
void traversetree(int root) {
	queue<struct node> q;
	q.push(treenode[root]);
	int count=0;
	while (!q.empty()) {
		struct node cnt = q.front();
		q.pop();
		if (cnt.left != null) {
			q.push(treenode[cnt.left]);
		}
		if (cnt.right != null) {
			q.push(treenode[cnt.right]);
		}
		if (cnt.left == null && cnt.right == null) {
			count++;
			if (count == 1) {
				cout << cnt.index;
			}
			else {
				cout << " " << cnt.index;
			}
		}
	}

}

int main() {
	int root = buildtree(treenode);
	traversetree(root);
}
