#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

void solve(){
    int n;
    cin >> n;
    
    map<int, int> mp;

    int size = n - 2;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x] ++;
    }

    for(auto x: mp){
        if(size % x.first == 0 && mp[size / x.first] >= 1){
            if(x.first == size / x.first && x.second < 2){
                continue;
            }
            cout << x.first << " " << size / x.first << endl;
            return;
        }        
    }
    cout << "-1" << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}