#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

vector<int> g[N];
int ans = 0;
int dep[N], son[N];

void dfs(int u, int fa = 0){
    dep[u] = 1;
    for(auto v: g[u]){
        if(v != fa){
            dfs(v, u);
            dep[u] = max(dep[u], dep[v] + 1);
            if(dep[v] > dep[son[u]]){
                son[u] = v;
            }
        }
    }
}

void go(int u, int fa = 0){
    for(auto v: g[u]){
        if(v != fa && v != son[u]){
            ans = max(ans, dep[v] - 1);
        }
    }
    if(son[u]){
        go(son[u], u);
    }
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    go(1);

    cout << dep[1] + max(ans, 0) << endl;
}