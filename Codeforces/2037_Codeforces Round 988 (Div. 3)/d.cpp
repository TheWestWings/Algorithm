#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
typedef long long ll;
typedef pair<int, int> pii;

void solve(){
    int n, m;
    long long L;
    cin >> n >> m >> L;
    
    vector<pii> o; //zhangai
    int mx = 0, mxi = -1;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        o.push_back({x, y});
    }

    vector<pii> bomb;
    // int s = 0;
    for(int i = 0, j = 0; i < m; i++){
        int x, v;
        cin >> x >> v;
        bomb.push_back({x, v});
                
    }

    priority_queue<int> pq;
    int s = 1;
    int ans = 0;
    for(int i = 0, j = 0; i < n; i ++){
        
        while(j < m && o[i].first >= bomb[j].first){
            pq.push(bomb[j].second);
            // s += bomb[j].second;
            j ++;
        }
        while(!pq.empty() && s <= o[i].second - o[i].first + 1){
            s += pq.top();
            pq.pop();
            ans ++;
        }

        if(pq.empty() && s <= o[i].second - o[i].first + 1){
            cout << "-1" << endl;
            return;
        }
        
    }
    cout << ans <<endl;



    


}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}