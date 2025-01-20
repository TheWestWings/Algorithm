#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n == 2){
        cout << 0 << endl;
        return;
    }

    int nn = n;
    
    int ans1 = 0;
    ans1 += n / 3 * 3;
    n = n / 3 + n % 3;
    ans1 += max(n / 2 * 3, n / 3 * 3 + (n / 3) / 2 * 3);
    
    int ans2 = 0;
    while(nn >= 3){
        int t = nn / 3 * 3;
        ans2 += t;
        nn = nn / 3 + nn % 3;
    }
    ans2 += nn / 2 * 3;
    cout << max(ans1, ans2) << endl;
}

signed main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}