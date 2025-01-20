#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
typedef pair<int, int> PII;

int e[N], ne[N], h[N], w[N],idx;
int dist[N];
bool st[N];
int n;

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void dijkstra(int n){
    memset(dist, 0x3f3f3f, sizeof(dist));
    
    priority_queue <PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    // st[1] = true;
    dist[1] = 0;
    
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        
        int ver = t.first, s = t.second;
        if(st[s]) continue;
        st[s] = true;
        
        for(int i = h[s]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[s] + w[i]){
                dist[j] = dist[s] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    
    // if(dist[n] == 0x3f3f3f3f) return -1;
    // return dist[n];

    int ans = 0;
    for(int i = 1; i <= n; i ++){
        // cout << dist[i] << " ";
        ans ^= dist[i];
    }
    cout << "ans " << ans << endl;
    
}

void solve(int n){
    
    // cin >> n;

    memset(h, -1, sizeof h);
    idx = 0;
    memset(st, 0, sizeof st);

    for(int i = 1; i <= n; i ++){
        // for(int j = i << 1; j <= n; j <<= 1){
        //     cout << i << " " << j << " " << (i ^ j) << endl;
        // }
        for(int j = i ; j <= n; j ++){
            // cout << i << " " << j << " " << (i ^ j) << endl;
            add(i, j, i ^ j);
            add(j, i, i ^ j);
        }
    }

    cout << n << " ";
    dijkstra(n);
    
}

int main(){
    int t;
    cin >> t;
    t = 100;

    while(t --){
        solve(100 - t);
    }
}