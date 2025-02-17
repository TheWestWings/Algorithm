#include <bits/stdc++.h>

using namespace std;

const int N = 10;

vector<int> a(N);

int main(){
    for(int i = 1; i <= 5; i ++) cin >> a[i];

    bool flag = false;
    for(int i = 1; i < 5; i ++){
        if(a[i] == i + 1 && a[i + 1] == i){
            swap(a[i], a[i + 1]);
            flag = true;
            break;
        }
    }

    if(!flag){
        cout << "No" << endl;
        return 0;
    }

    for(int i = 1; i <= 5; i ++){
        if(a[i] != i){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}