#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> s(n);
	for (int i = 0; i < n; i++) {
		cin>>s[i];
	}
	int sum = 0;
	int maxsum = 0;
	for (int i = 0; i < n; i++) {
		sum += s[i];
		if (sum > maxsum) {
			maxsum = sum;
		}
		else if (sum<0) {
			sum = 0;
		}
	}
	cout << maxsum;
}