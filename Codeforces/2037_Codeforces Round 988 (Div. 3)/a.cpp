#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    map<int, int> mp;

    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        mp[x] ++;
    }

    int cnt = 0;
    for(auto x: mp){
        while(x.second > 1){
            cnt ++;
            x.second -= 2;
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