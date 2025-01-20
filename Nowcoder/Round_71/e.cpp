#include <bits/stdc++.h>
#define double long double

using namespace std;

void solve(){
    int n;  
    cin >> n;

    map<int, int> mp;
    for(int i = 0; i < n; i ++){
        int x, y;
        cin >> x >> y;
        mp[x] += y;
    }

    vector<double> a, b;
    for(auto p: mp){
        a.push_back(p.first);
        if(p.second >= 2){
            b.push_back(p.first);
        }
    }

    double ans = -1;
    for(int i = 0; i < a.size(); i ++){
        int t = a[i];
        mp[t] --;
        for(int j = b.size() - 1; j >= 0; j --){
            if(2 * b[j] <= t) break;
            if(mp[b[j]] >= 2){      
            // cout << b[j] << " " << t << endl;
                double c = (t + 2 * b[j]) / 2.0;
                ans = max(ans, c * (c - b[j]) * (c - b[j]) * (c - t));
                break;
            }            
        }
        mp[t] ++;
    }
    if(ans == -1){
        cout << -1 << endl;
        return;
    }
    else cout << fixed << setprecision(12) << sqrt(ans) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}