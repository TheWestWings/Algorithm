#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 2);
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    map<int, int> mp;
    vector<pair<int, int>> qujian;
    int l = 1;
    for(int r = 1; r <= n; r ++){
        mp[a[r]] ++;
        if(mp.size() > 2){
            qujian.push_back({l, r - 1});
        }
        while(mp.size() > 2){
            mp[a[l]] --;
            if(mp[a[l]] == 0){
                mp.erase(a[l]);
            }
            l ++;
        }
    }
    if(mp.size() == 2){
        qujian.push_back({l, n});
    }

    int ans = 0;
    vector<int> s(n + 2);
    for(auto [l, r] : qujian){
        map<int, int> cnt;
        s[l - 1] = 0;
        cnt[0] = 1;
        for(int i = l; i <= r; i ++){
            s[i] = s[i - 1] + (a[i] == a[l] ? 1: -1);
            ans += cnt[s[i]];
            cnt[s[i]] ++;
        }
    }

    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }

    return 0;
}