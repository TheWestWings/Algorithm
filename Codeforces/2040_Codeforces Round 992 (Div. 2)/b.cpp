#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    if(n == 1){
        cout << 1 << endl;
        return;
    }
    if(n == 2){
        cout << 2 << endl;
        return;
    }

    

    int cnt = 1;
    int t = 1;
    while(t < n){
        cnt ++;
        t = (t + 1) * 2;
    }
    cout << cnt << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}