#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);		//µÝÔö¸³Öµ
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i ++) {
        cin >> w[i];
    }

    DSU uf(n);
    vector<int> first_seen_bit(60, -1); 

    for (int i = 0; i < n; i ++) {
        int num = w[i];
        for (int b = 0; b < 60; b ++) {
            if ((num >> b) & 1) {
                if (first_seen_bit[b] == -1) {
                    first_seen_bit[b] = i;
                }
                else{
                    uf.merge(i, first_seen_bit[b]);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i ++){
        ans = max(ans, uf.size(i));
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}