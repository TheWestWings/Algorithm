#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10;

void solve(){
    int n, k;
    cin >> n >> k;

    int s = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        s += a[i];
    }

    cout << s * k << endl;
}

signed main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}