#include <bits/stdc++.h>

using namespace std;

int bfs(int n, int k, int a, int b, int x, int y){
    queue<pair<int, int>> q;
    q.push({a, 0});
    // map<pair<int, int>, int> visited;
    vector<int> st(n + 1, 0);
    while(q.size()){
        
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();
        // cout << cur << endl;
        if(cur == b){
            // cout << cur << endl;
            return cost;
        }
        if(st[cur]){
            continue;
        }
        st[cur] = 1;
        q.push({(cur + x) % (n ), cost + 1});
        q.push({(cur - y + n) % (n), cost + 1}); 
    }
    return 0x3f3f3f3f;
}

int main(){
    int n, k, a, b, x, y;
    cin >> n >> k >> a >> b >> x >> y;

    a = (a - 1 + n) % n;
    b = (b - 1 + n) % n;
    // cout << "a: " << a << " b: " << b << endl;

    int ans = 0x3f3f3f3f;
    ans = min(ans, bfs(n, k, a, b, x, y)) ;
    // cout << ans << endl;
    if(k >= 1){
        a = (a + n / 2) % (n);      
        ans = min(ans, bfs(n, k, a, b, x, y) + 1);
    }
    
    cout << (ans == 0x3f3f3f3f ? -1 : ans) << endl;
}