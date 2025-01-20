#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;

void solve(int n, int m){
    // ll n, m;
    // cin >> n >> m;  

    ll sum_m = 0, sum_n = 0;
    
    for(ll d = 1; d <= m; d++){
        if(d <= n-1){
            sum_n = (sum_n + d * ((n-1) / d)) % mod;
        }
        sum_m = (sum_m + d * (m / d)) % mod;
    }
    
    ll result = sum_m - sum_n;
    cout << m << " " <<  (result % mod) << endl;
    
    return;
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 100;
    for(int i = 1; i <= t; i ++){
        solve(1, i);
    }
}