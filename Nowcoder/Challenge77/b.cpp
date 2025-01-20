#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10, mod = 1e9 + 7;
typedef long long ll;

ll a[N];
vector<ll> res(100, 0);
ll n, k, len;

// void turn2_k(ll x, int i){
//     // int i = 0;
//     ll t = 0;
//     while(x){
//         res[t] = (res[t] + (x % k) * (n - 1)) % k;
//         x /= k;
//         len = max(t, len);
//         t ++;
//     }
// }

// ll turn2_10(ll k, vector<ll> x){
//     ll res = 0;
//     ll base = 1;
//     for(int i = 0; i <= len; i ++){
//         res = (res + x[i] * base) % mod;
//         base *= k;
//     }
//     return res;

// }

ll qmi(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1){
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll mul_mod(ll a, ll b, ll mod){
    return (a % mod) * (b % mod) % mod;
}

int main(){
    
    cin >> n >> k;
    
    ll mx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        // turn2_k(a[i], i);   
    }

    ll ans = 0;
    ll p = 1;
    while(mx){
        vector<ll> cnt(k, 0);
        for(int i = 0; i < n; i++){
            cnt[a[i] % k] ++;
            a[i] /= k;
        }
for(int i = 0; i < k; i++){
    for(int j = i; j < k; j++){
        ll sum = (i + j < k) ? (i + j) : (i + j - k);
        ll count;
        
        if(i == j){
            count = mul_mod(cnt[i], cnt[i] - 1, mod) * qmi(2, mod - 2) % mod; // 若需要除以2，确保 mod 是质数并使用乘法逆元
        }
        else{
            count = mul_mod(cnt[i], cnt[j], mod);
        }
        
        ans = (ans + mul_mod(mul_mod(p, count, mod), sum, mod)) % mod;
    }
}
        p = p * k % mod;
        mx /= k;
    }

    cout << ans << endl;

    
}
