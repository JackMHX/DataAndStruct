#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void insertsort(vector<int> a,int p){
    p = min(int(a.size()), ++p);
    sort(a.begin(), a.begin() + p);
    for (int i = 1; i < a.size();i++){
        if(i!=1)
            cout<<" "<<a[i];
        else
            cout << a[i];
    }
}

void downadjust(vector<int>& a,int p){
    //在[a[1],a[p]]之间调整
    int i = 1;//根节点
    int j = 2 * i;//i的左孩子
    int high = p;
    while(j<=high){
        if(j+1 <= high&&a[j+1]>a[j]){
            j = j + 1;
        }
        if(a[j]>a[i]){
            swap(a[j], a[i]);
            i = j;
            j = i * 2;
        }
        else{
            break;
        }
    }

}

void heapsort(vector<int> a,int p){
    swap(a[1], a[p]);
    p--;
    downadjust(a, p);
    for (int i = 1; i < a.size();i++){
        if(i!=1)
            cout << " " << a[i];
        else
            cout << a[i];
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    vector<int> b(n+1);
    for (int i = 1; i < b.size();i++){
        cin >> b[i];
    }
    bool IsInsertsort = true;
    //int temp = ;
    int i;
    for (i = 1; i < b.size();i++){
        if(b[i]<b[i-1]){
            for (int j = i; j < b.size();j++){
                if(a[j]!=b[j]){
                    IsInsertsort = false;
                }
            }
            break;
        }
    }
    int p;
    if(!IsInsertsort){
        for (int i = b.size() - 1; i >= 2;i--){
            if(b[i]<b[i-1]){
                p = i;
                break;
            }
        }
    }

    if (IsInsertsort){
        cout << "Insertion Sort" << endl;
        insertsort(b,i);
    }
    else{
        cout << "Heap Sort" << endl;
        heapsort(b, p);
    }

    system("pause");
}