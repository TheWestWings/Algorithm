#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int ne[N], e[N], h[N], w[N], idx;

bool st[N];

int n, ans, mx;

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void dfs(int u, int d){
    if(d == 0){
        mx = max(mx, ans);
        return;
    } 
    // int res = 0;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(st[j]) continue;
        st[j] = true;
        // res += dfs(j, d - 1) + w[i];
        ans += w[i];
        dfs(j, d - 1);
        mx = max(mx, ans);
        ans -= w[i];
        st[j] = false;
    }
    // return res;
}

int main(){
    int n;

    cin >> n;

    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        // add(b, a, c);
    }

    int q;
    cin >> q;
    while(q --){
        int u, d;
        cin >> u >> d;
        ans = 0;
        mx = 0;
        dfs(u, d);
    }
}

