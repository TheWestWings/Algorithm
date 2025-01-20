#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

vector<int> g[N];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    
}