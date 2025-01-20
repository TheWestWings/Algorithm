#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> ans(n + 1);
    
    bool ok = true;
    for(int i = 0; i < n; i ++){
        vector<int> a(m);
        for(int j = 0; j < m; j ++){
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        if(a[0] >= n){
            ok = false;
        }
        else ans[a[0]] = i + 1;
        for(int j = 1; j < m; j ++){
            if(a[j] != j * n + a[0]){
                ok = false;
            }
        }
    }

    if(!ok){
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i < n; i ++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}