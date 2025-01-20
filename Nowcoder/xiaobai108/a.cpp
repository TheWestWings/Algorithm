#include <bits/stdc++.h>

using namespace std;

void solve(){
    int x, y;
    cin >> x >> y;
    x ++;
    int ans = y / x;
    if(y % x != 0){
        ans ++;
    }
    if(y == 0){
        cout << 0 << endl;
        return;
    }
    if(ans * x - x + 1 >= y){
        cout << ans * 2 - 1 << endl;
        return;
    }

    cout << ans * 2 << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}