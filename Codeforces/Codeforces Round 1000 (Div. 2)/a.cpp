#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    
    if(n == 1 && m == 1){
        cout << 1 << endl;
        return;
    }
    cout << m - n << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}