#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>arr1;
void InsertionSort(vector<int> &arr,int temp) {
	
	for (int i = temp; i < arr.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			}
		}
		break;
	}	
	for (int i = 0; i < arr.size(); i++) {
		if (i != 0) {
			cout << " " << arr[i];
		}
		else {
			cout << arr[i];
		}
	}
}

bool isequal(vector<int> a,vector<int> b) {
	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) { return false; }
		}
		return true;
	}
	return false;
}

void meg(vector<int> &a,vector<int>arr1) {
	int step = 1;
	int from, to;
	int n = a.size();
	bool find = false;
	while (1) {
		step = step * 2;
		for (int i = 0; i*step < n; i++) {
			from = i * step;
			to = min(from + step, n);
			//sort(&a[from],&a[to]);这个数据越界也能全过
			sort(a.begin()+from, a.begin()+to);		
		}
		if (find) {
			for (int i = 0; i < a.size(); i++) {
				if (i != 0) {
					cout << " " << a[i];
				}
				else {
					cout << a[i];
				}
			}
			break;
		}
		if (isequal(a,arr1)) {
			find = true;
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr1.push_back(num);
	}
	bool isinsertsort = true;
	int temp=0;
	for (int i = 1; i < n; i++) {
		if (arr1[i] < arr1[i - 1]) {
			temp = i;
			for (int j = i; j < n; j++) {
				if (arr1[j] != arr[j]) {
					isinsertsort = false;
				}
			}
			break;
		}
	}
	if (isinsertsort) {
		cout << "Insertion Sort" << endl;
		InsertionSort(arr1,temp);
	}
	else {
		cout << "Merge Sort" << endl;
		meg(arr,arr1);
	}
	system("pause");
}