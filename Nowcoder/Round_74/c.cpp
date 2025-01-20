#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    
    while(n >= 4 && k){
        n = ceil(sqrt(n));
        k --;
    }
    
    cout << n - k << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}