#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct TreeNode* tree;

struct TreeNode{
	int v;
	tree left;
	tree right;
	int flag;
};

tree NewNode(int v) {
	tree t = new TreeNode;
	t->v = v;
	t->left = NULL;
	t->right = NULL;
	t->flag = 0;
	return t;
}

tree Insert(tree t, int v) {
	if (!t) {
		t = NewNode(v);
	}
	else {
		if (v > t->v) {
			t->right = Insert(t->right, v);
		}
		else {
			t->left = Insert(t->left, v);
		}
	}
	return t;
}

tree MakeTree(int N) {
	tree t;
	int v;
	cin >> v;
	t = NewNode(v);
	for (int i = 1; i < N; i++) {
		cin >> v;
		t = Insert(t, v);
	}
	return t;
}

int check(tree t, int v) {
	/*
	如果flag==1那就是已经查找过了
	v<t.v那就检查t.left
	v>t.v那就检查t.right
	v==t.v那说明一个数重复出现了，这样也不是同意搜索树
	*/
	if (t->flag) {
		if (v < t->v) { return check(t->left,v); }
		else if (v > t->v) { return check(t->right,v); }
		else return 0;
	}
	/*
	如果flag==0那么还没查找过
	1、他可能是我们要查找的数，那么看看
	v==t.v？这是我们要查找的数：这不是我们要查找的数
	2、如果它不是我们要查找的数，说明后面的数提前出现了，
	   那么这就不是同意二叉搜索树
	*/
	else {
		if (v == t->v) {
			t->flag = 1;
			return 1;
		}
		else return 0;
	}
}

int judge(tree t, int n) {
	int i, v, flag = 1;
	cin >> v;
	if (v != t->v) { flag = 0; }//不是同一搜索树
	else t->flag = 1;
	for (i = 1; i < n; i++) {
		cin >> v;
		if ( !flag || !check(t, v)) { flag = 0; }//不是同一搜索树
	}
	return flag;
}


void ResetT(tree t) {
	if (t->left)ResetT(t->left);
	if (t->right)ResetT(t->right);
	t->flag = 0;
}
void FreeTree(tree t) {
	if (t->left) FreeTree(t->left);
	if (t->right) FreeTree(t->right);
	delete(t);
}

int main() {
	int N, L;
	tree t;
	vector<string> s;
	cin >> N;
	while (N!=0) {
		cin>> L;
		t = MakeTree(N);
		for (int i = 0; i < L; i++) {
			if (judge(t, N)) {
				s.push_back("Yes");
			}
			else {
				s.push_back("No");
			}
			ResetT(t);
		}
		FreeTree(t);
		cin >> N;
	}
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << endl;
	}
	system("pause");
}