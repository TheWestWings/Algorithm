#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7, N = 1e6 + 10;
int fact[N], inv_fact[N];

ll res[N][N]={0};
ll C(ll n,ll m){
    if(m==0 || m==n) return 1;
    if(res[n][m] != 0)return res[n][m];
    return res[n][m] = C(n-1,m)+ C(n-1,m-1);//赋值给res[n][m]并返回
}


void solve(){
    int n, k;
    cin >> n >> k;

    // cout << combination(0, 0) << endl;
    // cout << 1 << endl;
    // cout << (C(1, n / 2) % MOD) << endl; 
    // cout << ( C(k - 1, n - 1)) << endl;
    // cout << (C(1, n / 2) ) * C(k - 2 ,n - 2) << endl;
}

int main(){
    int t;
    cin >> t;
    // precompute();

    while(t --){
        solve();
    }
}