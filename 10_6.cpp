#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(int *s,int n){
    static int first=1;
    for (int i = first; i < n;i++){
        if(s[i]!=i){
            return first = i;
        }
    }
    return 0;
}
void swap(int *a,int n){
    int temp = a[0];
    a[0] = a[n];
    a[n] = temp;
}

int main(){
    int n;
    scanf("%d", &n);
    int s[n];
    int temp;
    for (int i = 0; i < n;i++){
        scanf("%d",&temp);
        s[temp]=i;
    }
    int num = 0;
    while(true){
        if(s[0]){
            swap(s,s[0]);
        }
        else{
            temp = search(s,n);
            if(!temp)
                break;
            else
                swap(s, temp);
        }
        num++;
    }
    printf("%d",num);
    system("pause");
}