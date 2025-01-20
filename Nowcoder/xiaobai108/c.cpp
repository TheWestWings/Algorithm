#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10;

int a[N];

void solve(){
    int n;
    cin >> n;

    map<int, int> mp;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        mp[a[i]] ++;
    }

    int ans = 0;
    for(auto [k, v]: mp){
        if(v % 2 == 0){
            ans += 2;
        }
        else if(v % 2 == 1){
            ans += 1;
        }
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