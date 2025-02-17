#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> pq[w + 1];
    map<int, int> mp;
    for(int i = 1; i <= n; i ++){
        int x, y;
        cin >> x >> y;

        mp[i] = x;
        pq[x].push_back({y, i});
    }

    for(int i = 0; i < w; i ++){
        sort(pq[i].begin(), pq[i].end());
    }

    bool flag = false;
    int lim = 1e9 + 10;
    for(int i = 1; i <= w; i ++){
        if(pq[i].size() == 0){
            flag = true;
        }
        lim = min(lim, (int)pq[i].size());
    }

    vector<int> ans(n + 1, 1e9 + 10);
    for(int i = 0; i < lim; i ++){
        int mx = 0;
        for(int j = 1; j <= w; j ++){
            mx = max(mx, pq[j][i].first);
        }
        for(int j = 1; j <= w; j ++){
            ans[pq[j][i].second] = mx;
        }
    }

    int q;
    cin >> q;

    while(q --){
        int t, a;
        cin >> t >> a;
        // cout << a << " " << ans[a] << " " << t << endl;

        if(ans[a] <= t){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }

        // if(flag){
        //     cout << "Yes" << endl;
        //     continue;
        // }
       
        // int x = mp[a];
        // int index = -1;
        // int l = 0, r = pq[x].size();
        // while(l < r){
        //     int mid = (l + r) / 2;
        //     if(pq[x][mid].second == a){
        //         index = mid;
        //         break;
        //     }
        //     else if(pq[x][mid].second < a){
        //         l = mid + 1;
        //     }
        //     else{
        //         r = mid;
        //     }
        // }

        // int ans = 0;
        // int mn = pq[x][index].first;
        // for(int i = 1; i <= w; i ++){
        //     // cout << pq[i].size() << " " << index << endl;
        //     if(pq[i].size() < index + 1){
        //         mn = 1e9 + 10;
        //         break;  
        //     }
        //     mn = max(mn, pq[i][index].first);
        // }
        // if(mn <= t){
        //     cout << "No" << endl;
        // }
        // else{
        //     cout << "Yes" << endl;
        // }
    }
}