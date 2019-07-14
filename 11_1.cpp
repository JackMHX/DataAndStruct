#include <iostream>

#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	unordered_map<long long, int> mp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long s1, s2;
		cin >> s1 >> s2;
		auto it = mp.find(s1);
		if (it != mp.end()) {
			(it->second)++;
		}
		else {
			mp.insert(pair<long long, int>(s1, 1));
		}
		it = mp.find(s2);
		if (it != mp.end()) {
			(it->second)++;
		}
		else {
			mp.insert(pair<long long, int>(s2, 1));
		}
	}
	auto max_num = mp.begin();
	int amount = 0;
	for (auto i = mp.begin(); i != mp.end(); i++) {
		if (i->second > max_num->second) {
			max_num = i;
			amount = 1;
		}
		else if (i->second == max_num->second) {
			amount++;
			if (i->first < max_num->first) {
				max_num = i;
			}
		}
	}
	if(amount==1)
		cout << max_num->first << " " << max_num->second;
	else
		cout << max_num->first << " " << max_num->second<<" "<<amount;
	system("pause");
}