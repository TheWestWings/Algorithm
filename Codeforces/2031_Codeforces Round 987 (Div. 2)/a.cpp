#include <bits/stdc++.h>

using namespace std;

const int N = 60;

int a[N], cnt[N];

void solve(){
    int n;
    cin >> n;

    int ans = n;
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        cnt[a[i]] ++;
        ans = min(ans, n - cnt[a[i]]);
        // b[i] = a[i];
    }

    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}