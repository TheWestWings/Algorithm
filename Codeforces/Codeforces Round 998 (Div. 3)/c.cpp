#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        mp[a[i]] ++;
    }

    int cnt = 0;
    for(int i = 0; i < n; i ++){
        if(mp[k - a[i]] && k - a[i] != a[i] && mp[a[i]]){
            cnt ++;
            mp[k - a[i]] --;
            mp[a[i]] --;
        }
        else if(mp[k - a[i]] > 1 && k - a[i] == a[i]){
            cnt ++;
            mp[k - a[i]] -= 2;
        }
    }
    cout << cnt << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}