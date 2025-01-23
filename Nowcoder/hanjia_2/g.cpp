#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    if(m == 1){
        cout << 1 << endl;
        return;
    }

    int t = m * m;
    int mn =  abs(n - m);
    int ans = 1;
    int cnt = 1;
    for(int i = t; i <= 1e10; i *= m){
        cnt ++;
        if(abs(n - i) < mn){
            ans = cnt;
            mn = abs(n - i);
        }
    }
    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}