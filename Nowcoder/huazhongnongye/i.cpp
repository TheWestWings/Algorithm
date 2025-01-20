#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_S = 200005;
const int MOD = 1000000007;

// 预计算阶乘和逆元
ll fact[MAX_S];
ll inv_fact[MAX_S];
ll inv_num[MAX_S];

// 预计算阶乘
void compute_fact() {
    fact[0] = 1;
    for(int i = 1; i < MAX_S; ++i){
        fact[i] = fact[i-1] * i % MOD;
    }
}

// 预计算逆元
void compute_inv() {
    inv_num[1] = 1;
    for(int i = 2; i < MAX_S; ++i){
        inv_num[i] = MOD - (MOD / i) * inv_num[MOD % i] % MOD;
    }
    inv_fact[0] = 1;
    for(int i = 1; i < MAX_S; ++i){
        inv_fact[i] = inv_fact[i-1] * inv_num[i] % MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    compute_fact();
    compute_inv();
    
    int T = 1;
    // cin >> T;
    while(T--){
        ll n;
        int s;
        cin >> n >> s;
        // 计算 C(n + s, s +1) mod MOD
        ll res = 1;
        ll n_mod = n % MOD;
        for(int i =1; i <= s +1; ++i){
            ll term = (n_mod + s - i +1) % MOD;
            res = res * term % MOD;
            res = res * inv_num[i] % MOD;
        }
        // 计算 s! mod MOD
        ll s_fact = fact[s];
        // 最终答案
        ll ans = s_fact * res % MOD;
        cout << ans << "\n";
    }
}