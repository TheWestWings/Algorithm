#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
typedef pair<int, int> PII;

vector<int> g[2 * N];
PII d[N];
bool st[N];

void dfs(int u){
    // cout << u << " ";
    st[u] = true;
    for(int v : g[u]){
        if(!st[v]){
            dfs(v);
        }
    }
}

void solve(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        g[i].clear();
        d[i] = {0, i};
        st[i] = false;
    }

    int mxi = -1, mx = -1;
    int cnt = 0;
    for(int i = 0; i < n - 1; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);

        d[u].first ++;
        d[v].first ++;

        if(d[u].first > mx){
            mx = d[u].first;
            mxi = u;
        }
        if(d[v].first > mx){
            mx = d[v].first;
            mxi = v;
        }

    }

    // sort(d + 1, d + n + 1, greater<PII>());

    multiset<int> mxs;
    for(int i = 1; i <= n; i ++){
        if(d[i].first == mx){
            mxs.insert(d[i].second);
        }
    }

    if(mxs.size() > 2){
        for(auto x: mxs){
            bool flag = false;  
            for(auto y: g[x]){
                if(mxs.find(y) != mxs.end()){
                    flag = true;
                    break;
                }
            }
            if(!flag) mxi = x;
        }
    }

    // for(int i = 1; i <= n; i ++){
    //     cout << d[i].first << " " << d[i].second << endl;
    // }

    for(auto x: g[mxi]){
        d[x].first --;
    }
    // cout << mxi << endl;

    // for(int i = 1; i <= n; i ++){
    //     cout << d[i].first << " " << d[i].second << endl;
    // }

    sort(d + 1, d + n + 1, greater<PII>());

    st[d[1].second] = st[d[2].second] = true;
    // cout << d[1].second << " " << d[2].second << endl;

    int ans = 0;
    for(int i = 1; i <= n; i ++){
        if(!st[i]){
            // cout << "====================" << i << endl;
            dfs(i);
            ans ++;
            // cout << endl;
            // cout << "====================" << i << endl;
        }
    }

    if(n <= 2){
        cout << 0 << endl;
        return;
    }

    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}