#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;

// int a[N];

void solve(){
    int n;
    cin >> n;

    int ans = 0;
    int s = 0;
    vector<int> a(n + 1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
        ans = max(ans, a[i]);
    }
    sort(a.begin(), a.end(), greater<int>());
    if(s == ans) cout << -1 << endl;
    else if(ans == 1) cout << 0 << endl;
    else if(a[1] == 1) cout << a[0] - 1 << endl;
    else cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}