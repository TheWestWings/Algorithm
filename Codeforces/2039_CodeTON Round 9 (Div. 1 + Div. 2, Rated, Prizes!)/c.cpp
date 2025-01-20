#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    ll x, m;
    cin >> x >> m;

    ll ans = 0;
    for(ll i = 1; i < m; i ++){
        // cout << x << " " << (x ^ i) << " " <<  ((x ^ i) ^ x) << endl;
        if((x ^ i) <= m && ((x ^ i) % ((x ^ i) ^ x) == 0 || x % ((x ^ i) ^ x) == 0)){
            // cout << i << endl;
            ans ++;
            // cout << (x ^ i) << endl;
            // return ;
        }
        // if(x ^ i ){
        //     cout << i << endl; 
        //     return ;
        // }
        // cout << 1 << endl;
        // cout << (x ^ i) << endl;
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