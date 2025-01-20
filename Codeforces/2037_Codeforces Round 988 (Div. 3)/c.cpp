#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

void solve(){
    int n;
    cin >> n;
    if(n < 5){
        cout << "-1" << endl;
        return;
    }
    for(int i = 1; i <= n; i ++){
        if(i != 5 && i % 2 != 0){
            cout << i << " ";
        }
    }
    cout << "5 4 ";

    for(int i = 1; i <= n; i ++){
        if(i != 4 && i % 2 == 0){
            cout << i << " ";
        }
    }
    return ;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}