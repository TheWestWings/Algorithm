#include <bits/stdc++.h>

using namespace std;

void solve(){
    int l, r, k;
    cin >> l >> r >> k;

    int ans = r / k - l + 1;
    if(ans > 0){
        cout << ans << endl;
        return;
    }
    else{
        cout << 0 << endl;
        return;
    }
    // cout << r / k - l + 1<< endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}