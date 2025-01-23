#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    auto b = a;
    sort(b.begin() + 1, b.begin() + r + 1, greater<int>());
    int ans1 = 0;
    for(int i = l; i <= r; i ++) ans1 += b[i];
    // for(int i = 1; i <= n; i++) cout << b[i] << " ";
    // cout << endl;

    auto c = a;
    sort(c.begin() + l, c.end());
    int ans2 = 0;
    for(int i = l; i <= r; i++) ans2 += c[i];
    // for(int i = 1; i <= n; i++) cout << c[i] << " ";
    // cout << endl;

    cout << min(ans1, ans2) << endl;

 
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}