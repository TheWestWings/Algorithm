#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    int n;
    cin >> n;

    vector<pair<char, int>> v;
    for(int i = 0; i < n; i ++){
        char c;
        int t;
        cin >> t >> c;
        v.push_back({c, t});
    }

    int m;
    cin >> m;

    string t;
    cin >> t;

    if(m == 1){
        int ans = 0;
        for(int i = 0; i < n; i ++){
            if(v[i].first == t[0]){
                ans += v[i].second;
                
            }
        }
        cout << ans << endl;
    }   
    else{
        int ans = 0;
        if(t[0] == t[1]){
            for(int i = 0; i < n; i ++){
                if(v[i].first == t[0]){
                    ans += v[i].second - 1;
                }
            }
        }
        else{
            for(int i = 0; i < n - 1; i ++){
                if(v[i].first == t[0] && v[i + 1].first == t[1]){
                    ans ++;
                }
            }
        }
        cout << ans << endl;
    }
}