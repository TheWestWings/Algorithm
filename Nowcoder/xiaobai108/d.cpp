#include <bits/stdc++.h>
#define int long long

using namespace std;
int m;
int ans = 0;

bool check(int x){
    int sum = (1 + x) * x / 2;
    sum *= x;
    // cout << sum << endl;
    int t = x * (x + 1) * (2 * x + 1) / 6;
    t -= x * (x + 1) / 2;
    sum -= t;
    // cout << x << " " << sum << endl;
    // if(sum > m) ans = x - 1;
    // else if(sum == m) ans = x;
    return sum >= m;
}

void solve(){
    cin >> m;

    int l = 0, r = 2e6;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)){
            ans = mid;
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans + 1 << endl;

}

signed main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }

}