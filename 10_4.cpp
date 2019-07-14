#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b(51);
    for (int i = 0; i < a.size();i++){
        b[a[i]]++;
    }
    for (int i = 0; i < b.size();i++){
        if(b[i]!=0){
            cout << i << ":" << b[i] << endl;
        }
    }
    system("pause");
}