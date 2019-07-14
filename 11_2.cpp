#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int a[100010] = { 0 };
int b[100010] = { 0 };

bool isprime(int num) {
	if (num < 2)
		return false;
	for (int i = 2; i * i < num; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int main() {
	//auto t = isprime(11);

	int msize, nsize;
	cin >> msize >> nsize;//表长，数字个数
	while (isprime(msize)==false) {
		msize++;
	}

	for (int i = 0; i < nsize; i++) {
		a[i] = -1;
	}
	int num;
	for (int i = 0; i < nsize; i++)
	{
		cin >> num;
		for (int j = 0; j < msize; j++) {
			int p;
			p = (num + j * j) % msize;
			if (b[p] == 0) {
				a[i] = p;//把p存进去,p就是num这个数的位置
				b[p] = 1;//1表示存了p这个位置有数了
				break;
			}
		}
	}
	for (int i = 0; i < nsize; i++) {
		if (i == 0) {
			if (a[i] == -1) {
				cout << "-";
			}
			else {
				cout << a[i];
			}
		}
		else {
			if (a[i] == -1) {
				cout << " " << "-";
			}
			else {
				cout << " " << a[i];
			}
		}
	}
}