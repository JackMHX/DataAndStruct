#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void MinHeapFixup(vector<int> &v,int data) {
	//i节点的父节点下标(i-1)/2
	//左右子节点    2*i+1   2*i+2
	v.push_back(data);
	int position = v.size() - 1;
	int father = (position - 1) / 2;
	while (father>=0 && position!=0)
	{
		if (v[father] <= data) { break; }
		v[position] = v[father];
		position = father;
		father = (position - 1) / 2;
	}
	v[position] = data;
}

void Print(vector<int> a) {
	for (int i = 0; i < a.size(); i++) {
		if (i != 0) { cout << " " << a[i]; }
		else { cout << a[i]; }
	}
}
//堆化数组
void MakeHeap(vector<int> &a, int i) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int small = i;
	if (l<a.size()&&a[l]<a[i])
	{
		small = l;
	}
	if (r<a.size()&&a[r]<a[i])
	{
		small = r;
	}
	if (small != i) {
		swap(a[small], a[i]);
		MakeHeap(a, small);
	}

}

void MakeMinHeap(vector<int>& a, int n) {
	for (int i = n / 2; i >= 0; i--) {
		MakeHeap(a, i);
	}
}

void PrintItsFather(vector<int> &a, int position) {
	position--;
	vector<int> f;
	while (position!=0)
	{

		f.push_back(a[position]);
		position = (position - 1) / 2;
	}
	f.push_back(a[position]);
	for (int i = 0; i < f.size(); i++) {
		if (i != 0) 
		{
			cout << " " << f[i];
		}
		else
		{
			cout << f[i];
		}
	}
	cout << endl;
}

int main() {
	int n, m;
	cin >> n >> m;//n插入元素的个数，m需要打印的路径条数
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		MinHeapFixup(v,data);
		/*v.push_back(data);*/
	}
	/*MakeMinHeap(v, v.size() - 1);*/
	//Print(v);
	vector<int> positionfind;
	for (int i = 0; i < m; i++) {
		int position;
		cin >> position;
		positionfind.push_back(position);
	}
	for (int i = 0; i < positionfind.size(); i++) {
		PrintItsFather(v, positionfind[i]);
	}
	system("pause");
}