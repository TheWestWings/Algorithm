#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
typedef pair<int, int> PII;

vector<int> g[2 * N];
int d[N];
multiset<int> s;
int ans = 0;

void dfs(int u, int fa){
    for(int v : g[u]){
        if(v == fa) continue;
        dfs(v, u);
        ans = max(ans, d[u] + d[v] - 2);
    }

    s.erase(s.find(d[u]));
    for(int v : g[u]) s.erase(s.find(d[v]));
    if(s.size()) ans = max(ans, d[u] + (*s.rbegin()) - 1);
    for(int v : g[u]) s.insert(d[v]);
    s.insert(d[u]);
}

void solve(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        g[i].clear();
        d[i] = 0;
    }

    
    s.clear();
    for(int i = 0; i < n - 1; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);

        d[u] ++;
        d[v] ++;
    }

    for(int i = 1; i <= n; i ++) s.insert(d[i]);
    
    dfs(1, -1);

    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ans = 0;
        solve();
    }
    return 0;
}