#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e6 + 10;

int a[N];

void solve(){
    int n, k;
    cin >> n >> k;

    int mx1 = 0, mx2 = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] > mx1){
            mx2 = mx1;
            mx1 = a[i];
        }
        else if(a[i] > mx2){
            mx2 = a[i];
        }
    }

    if(n == 1){
        cout << a[0] << endl;
        return;
    }
    else if(n == 2){
        cout << a[0] + a[1] << endl;
        return;
    }

    int t = n - k;
    if(t < 2){
        // cout << mx1 + mx2 << endl;
        // return;
        t = 2;
    }
    int ans = 0;
    int mx =0;
    for(int i = 0; i + t - 1 < n; i ++){
        // cout << a[i + t - 1] << " " << a[i] << endl;
        mx = max(mx, a[i]);
        ans = max(ans, mx + a[i + t - 1]);
    }

    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}