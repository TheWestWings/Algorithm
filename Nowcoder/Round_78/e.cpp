#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;

vector<int> g[N];
map<int, int> mp;
bool st[N];
// int cnt = 0;

int dfs(int u, int fa){
    if(st[u]) return 0;
    st[u] = 1;
    int cnt = 0;
    for(auto v : g[u]){
        if(v == fa) continue;
        if(mp[v]){
            cnt = (cnt + dfs(v, u)) % mod;
        }
        else{
            // cout << v << endl;
            cnt ++;
        }
    }

    return cnt % mod;
}

signed main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i ++){
        int x;
        cin >> x;

        mp[x] = 1;
    }

    for(int i = 0; i < n - 1; i ++){
        int v, u;
        cin >> v >> u;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    int ans = 1, cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(!st[i] && mp[i]){
            cnt ++;
            int t = dfs(i, -1);
            // cout << "============" << endl;
            // cout << t << endl;
            ans = (ans % mod * t % mod) % mod;
        }
    }
    
    cout << cnt << " " << ans << endl;
}