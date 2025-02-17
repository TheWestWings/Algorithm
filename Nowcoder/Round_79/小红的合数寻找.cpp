#include <bits/stdc++.h>

using namespace std;

void solve(){
        int x;
    cin >> x;
    
    if(x != 1) cout << 2 * x << endl;
    else cout << -1 << endl;
}

int main(){
    int t = 1;
    // cin >> t;

    while(t --){
        solve();
    }
}