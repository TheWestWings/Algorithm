#include <bits/stdc++.h>
using namespace std;

// Global structures
static const int MAXN = 500000;
vector<int> adj[MAXN + 1];
int parent[MAXN + 1], depth[MAXN + 1], heavy[MAXN + 1], sizeSub[MAXN + 1];
int head[MAXN + 1], pos[MAXN + 1], currentPos;
long long segtree[4 * (MAXN + 1)], lazy[4 * (MAXN + 1)];
// sumVal[u] = (number of reds in subtree u) - (number of blues in subtree u)
long long sumVal[MAXN + 1];

// 1. DFS to find heavy child and compute subtree sizes
int dfs(int u, int p) {
parent[u] = p;
depth[u] = (p == -1 ? 0 : depth[p] + 1);
sizeSub[u] = 1;
int maxSubtree = -1;
for (int v : adj[u]) {
if (v == p) continue;
int sz = dfs(v, u);
sizeSub[u] += sz;
// Heavy edge = child with the largest subtree
if (sz > maxSubtree) {
maxSubtree = sz;
heavy[u] = v;
}
}
return sizeSub[u];
}

// 2. Decompose into heavy chains
void decompose(int u, int h) {
head[u] = h;
pos[u] = currentPos++;
// If there is a heavy child, decompose it first
if (heavy[u] != -1) {
decompose(heavy[u], h);
}
// Decompose other children
for (int v : adj[u]) {
if (v == parent[u] || v == heavy[u]) continue;
decompose(v, v);
}
}

// Segment Tree utility for sum of ¡°|sum_u|¡± changes.
// Usually we¡¯d maintain an array that stores |sumVal[u]| at pos[u],
// and on flipping, we apply ¡À2 to all ancestors¡¯ segments.
void buildSegTree(/* ... */) {
// Build from the array that stores |sumVal[u]| initially
}

void applyRangeUpdate(/* ... */) {
// Propagate a lazy update that accounts for how adding ¡À2 affects |oldVal|.
// The absolute-value nature means we need a careful approach or store sumVal[u] directly.
// A full solution requires segment tree with lazy propagation
// that can recalc each node¡¯s contribution to the sum of absolute values.
}

long long queryPath(int u, int v /* ¡À2 type */) {
// Repeatedly move top of heavy chain until heads match,
// updating the segment tree with the ¡À2 effect.
// Summation of (|sumVal[u] ¡À 2| - |sumVal[u]|).
// This function would accumulate the total difference for the path u->v.
}

// Main solve function
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);

int T;
cin >> T;
while (T--) {
    int n; 
    cin >> n;

    // Read colors
    string s;
    cin >> s;

    // Clear adjacency
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        heavy[i] = -1;
        // sumVal[i] = +1 if R, -1 if B
        sumVal[i] = (s[i-1] == 'R' ? 1 : -1);
    }

    // Read edges
    for (int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 1) DFS from root (problem states root=1)
    dfs(1, -1);
    // 2) Heavy-Light Decomposition
    currentPos = 0;
    decompose(1, 1);
    // 3) Build segment tree or Fenwick for storing contributions
    buildSegTree();

    // Precompute the initial total S = sum of |sumVal[u]| for all u
    // (done in buildSegTree or a separate pass)

    // 4) For each node x, we want to flip color and see if S decreases.
    // We check the path from x to root (x->1) with a ¡À2 update
    // and see how it changes the sum of absolute values.
    // Then revert that change for the next query.
    // Output '1' if it decreases S, else '0'.
    
    string answer(n, '0');
    for(int x = 1; x <= n; x++) {
        // Determine sign flip (+2 or -2)
        // if sumVal[x] > 0 means currently +1, flipping => -1 => delta = -2
        // if sumVal[x] < 0 means currently -1, flipping => +1 => delta = +2
        int flip = (sumVal[x] > 0 ? -2 : 2);
        
        // Query the difference for path (x, 1)
        long long diff = queryPath(x, 1 /* flip */);
        // If diff < 0 => new total is S + diff => smaller
        if (diff < 0) {
            answer[x-1] = '1';
        }
        // Revert (important for next node¡¯s check)
        queryPath(x, 1 /* -flip */);
    }

    cout << answer << "\n";
}

return 0;
}