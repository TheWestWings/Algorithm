#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N];

void solve(){
    int n;
    cin >> n;

    string str;
    cin >> str;
    str = " " + str;

    map<char, pair<int, int>> mp;
    int ans = 0x3f3f3f3f;
    for(int i = 1; i <= n; i ++){
        if(mp[str[i]].first == 0){
            mp[str[i]].first = i;
        }
        else{
            int t = n - (i - mp[str[i]].first - 1) - 2;
            ans = min(ans, t);
            if(mp[str[i]].second == 0){
                t = i - mp[str[i]].first - 1;
                ans = min(ans, t);
                mp[str[i]].second = i;
                continue;
            }
            t = i - mp[str[i]].second - 1;
            mp[str[i]].second = i;
            ans = min(ans, t);
        }
    }
    // cout << ans ==  << endl;
    cout << (ans == 0x3f3f3f3f ? -1 : ans) << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}