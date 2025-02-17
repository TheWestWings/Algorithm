#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 50 + 5, inf = 1e18, M = 105;
const ld eps = 1e-12;

vector<int> adj[N];
vector<int> ans;
int deg[N], used[N][N];

void dfs(int u) {
    for (int& v : adj[u]) {
        if (!used[u][v]) {
            used[u][v] = used[v][u] = 1;
            dfs(v);
        }
    }
    ans.push_back(u);
}

void solve() {
    int n; cin >> n;
    n++;
    int total = n * (n + 1) / 2;
    auto id = [&](int r, int c) {
        return (r * (r - 1)) / 2 + c;
        };
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= r; c++) {
            int u = id(r, c);
            if (c < r) {
                int v = id(r, c + 1);
                adj[u].push_back(v); adj[v].push_back(u);
                deg[u]++; deg[v]++;
            }
            if (r < n) {
                int v = id(r + 1, c);
                adj[u].push_back(v); adj[v].push_back(u);
                deg[u]++; deg[v]++;
                v = id(r + 1, c + 1);
                adj[u].push_back(v); adj[v].push_back(u);
                deg[u]++; deg[v]++;
            }
        }
    }
    int odd = 0, start = 1;
    for (int i = 1; i <= total; i++) {
        if (deg[i] & 1) { odd++; start = i; }
    }
    if (odd != 0 && odd != 2) { cout << "No\n"; return; }
    dfs(start);
    if (ans.size() - 1 != accumulate(deg + 1, deg + 1 + total, 0) / 2) { cout << "No\n"; return; }
    cout << "Yes\n";
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << (i + 1 < (int)ans.size() ? ' ' : '\n');
    }

}

int main(){
    solve();
}