#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
    int x;
    cin >> x;

    int ans = 1;
    while(x > 3){
        ans *= 2;
        x /= 4;
    }
    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
} 