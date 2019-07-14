// #include <iostream>
// #include <vector>


// using namespace std;

// void merge(vector<long long> &a, int l, int mid, int r) {
// 	vector<int>help(r-l+1);
// 	int i = 0;
// 	int p1 = l;
// 	int p2 = mid + 1;
// 	while (p1 <= mid && p2 <= r) {
// 		help[i++] = a[p1] < a[p2] ? a[p1++] : a[p2++];
// 	}
// 	while (p1 <= mid) {
// 		help[i++] = a[p1++];
// 	}
// 	while (p2 <= r) {
// 		help[i++] = a[p2++];
// 	}
// 	for (int i = 0; i < help.size(); i++) {
// 		a[l+i] = help[i];
// 	}
// }

// void Mergesort(vector<long long> &a, int l, int r) {
// 	if (l == r) {
// 		return;
// 	}
// 	int mid = (l + r) / 2;
// 	Mergesort(a, l, mid);
// 	Mergesort(a, mid + 1, r);
// 	merge(a,l,mid,r);

// }
// void Mergesort(vector<long long>&a) {
// 	if (a.size() < 2) {
// 		return;
// 	}
// 	Mergesort(a, 0, a.size() - 1);
// }


// int main() {
// 	vector<long long> v;
// 	int n;
// 	cin>>n;
// 	/*while (cin>>data)
// 	{
// 		v.push_back(data);
// 	}*/
// 	for(int i = 0;i<n;i++){
// 	  int data;
// 	  cin>>data;
// 	  v.push_back(data);
// 	}
// 	Mergesort(v);
// 	for (int i = 0; i != v.size(); i++) {
// 		if(i==0){
// 		  cout << v[i];
// 		}
// 		else{
// 		  cout<<" "<<v[i];
// 		}
// 	}

// 	system("pause");

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> v;
	for (int i = 0; i < n; ++i) {
		long long data;
		cin >> data;
		v.push_back(data);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i != v.size(); ++i) {
		if (i == 0) { cout << v[i]; }
		else { cout <<" "<< v[i]; }
	}
}
