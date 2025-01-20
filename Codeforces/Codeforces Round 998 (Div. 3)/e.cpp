#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    map<pair<int, int>, int> mp;
    for(int i = 0; i < m1; i ++){
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        mp[{u, v}] ++;
    }

    int cnt = 0, add = 0;
    for(int i = 0; i < m2; i ++){
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        if(mp[{u, v}]){
            cnt ++;
            mp[{u, v}] --;
        }
        else{
            add ++;
        }
    }

    cout << m1 - cnt + add << endl; 
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}