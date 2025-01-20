#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5  + 10;

int a[N], s[N];

signed main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    // for(int i = 1; i <= n; i++){
    //     cout << s[i] << " ";
    // }
    // cout << endl;

    int mx = -1e18, ans = -1e18;
    for(int i = 1; i <= n; i ++){
        mx = max(mx, -s[i]);
        ans = max(ans, s[i] + mx - (s[n] - s[i]) + mx);
    }
    cout << ans << endl;

    
}