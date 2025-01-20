#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int a[N];

void solve(){
    int n;
    cin >> n;

    map<int, int> cnt;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        cnt[a[i]] ++;
    }

    int res = 0;
    for(auto mp: cnt){
        if(mp.second == 1){
            res ++;
        }
    }

    cout << (res + 1) / 2 * 2 + cnt.size() - res << endl; 
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}