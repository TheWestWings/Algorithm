#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 10, MOD = 1e9 + 7;

// Fast exponentiation to compute a^b mod MOD
int qmi(int a, int b){
    int res = 1;
    a %= MOD;
    while(b){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    // 使用不同的变量名，避免与全局数组冲突
    vector<int> arr(n + 1), b(n + 1), sa(n + 1, 0), sb(n + 1, 0);
    for(int i = 1; i <= n; i ++){
        cin >> arr[i];
    }
    
    sort(arr.begin() + 1, arr.end());

    for(int i = 1; i <= n; i ++){
        sa[i] = (sa[i - 1] + arr[i]) % MOD;
        b[i] = ((arr[i] + 1) * arr[i] / 2) % MOD;
        sb[i] = (sb[i - 1] + b[i]) % MOD;
    }

    for(int j = 1; j <= k; j ++){
        int r;
        cin >> r;
        int u = upper_bound(arr.begin(), arr.end(), r) - arr.begin();
        
        // 修正取余操作，确保 t 为非负数
        int t = (sa[n] - sa[u - 1] + MOD) % MOD;
        
        int ans = (t + t - (r - 1) * (n - u + 1) % MOD) * r % MOD;
        ans = ans * qmi(2, MOD - 2) % MOD;
        ans = (ans + MOD) % MOD;
        
        cout << (sb[u - 1] + ans) % MOD  << "\n";
    }
}