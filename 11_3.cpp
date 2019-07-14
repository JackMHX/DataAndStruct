#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main() {
	map<string, string> mp;
	vector<string> res;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char cmd;
		string qq;
		string password;
		cin >> cmd >> qq >> password;
		auto it = mp.find(qq);
		if (cmd == 'L') {
			if (it == mp.end()) {
				//cout << "ERROR: Not Exist" << endl;//qq号不存在
				res.push_back("ERROR: Not Exist");
			}
			else if (it->second != password) {
				//cout << "ERROR: Wrong PW" << endl;//密码错误
				res.push_back("ERROR: Wrong PW");
			}
			else {
				//cout << "Login: OK" << endl;
				res.push_back("Login: OK");
			}
		}
		else if (cmd == 'N') {
			if (it == mp.end()/*qq号还没被创建过*/) {
				mp.insert(pair<string, string>(qq, password));
				//cout << "New: OK";
				res.push_back("New: OK");
			}
			else {
				//qq号已存在
				//cout << "ERROR: Exist";
				res.push_back("ERROR: Exist");
			}
		}
	}
	for (auto i = res.begin(); i != res.end(); i++) {
		cout << *i << endl;
	}
	system("pause");
}