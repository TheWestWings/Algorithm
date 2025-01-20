#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e3 + 10;

int h[N], c[N];

signed main(){
    int n, k, q;
    cin >> n >> k >> q;

    for(int i = 1; i <= n; i ++){
        cin >> h[i] >> c[i];
    }

    while(q --){
        int x;
        cin >> x;

        int k_now = k - c[x];
        if(k_now < 0){
            cout << - 1 << endl;
            continue;
        }
        vector<vector<int>> f(n + 1, vector<int>(k_now + 1, 0));
        for(int i = 1; i <= n; i ++){
            // if(i == x){
                
            // }
            for(int j = 1; j <= k_now; j ++){
            f[i][j] = f[i - 1][j];
            if(i == x) continue;
            if(j - c[i] >= 0)f[i][j] = max(f[i - 1][j], f[i - 1][j - c[i]] + h[i]);
            }
        }
        // cout << x << endl;
        // cout << n << " " << k_now << endl;
        cout << f[n][k_now] + h[x] << endl;

    }
    
}