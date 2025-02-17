#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin >> n;

    int ans = 1;
    int t = 2;
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    else if(n == 2){
        cout << 1 << endl;
        return;
    }
    for(int i = 2; i < n; i ++){
        ans = (ans + t * 3 % mod) % mod; 
        t = t * 2 % mod;
    }
    cout << ans % mod << endl;
}

signed main(){
    int t = 1;
    // cin >> t;

    while(t --){
        solve();
    }
}