#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5 + 10;

int a[N], b[N], c[N], as[N];

void solve(){
    int m, n;
    cin >> m >> n;

    for(int i = 1; i <= m; i ++){
        cin >> a[i];
    }

    sort(a + 1, a + m + 1);
    
    for(int i = 1; i <= m; i ++){
        as[i] = as[i - 1] + a[i];
    }

    for(int i = 1; i <= n; i ++){
        cin >> b[i];
    }

    for(int i = 1; i <= n; i ++){
        cin >> c[i];
    }

    int x;
    cin >> x;
    for(int i = 1; i <= n; i ++){
        if(c[i] > m){
            cout << "NO" << endl;
            return;
        }
        x -= as[c[i]] + (b[i] - c[i]) * a[1];
    }
    // cout << x << endl;
    if(x >= 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

signed main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}