#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    for(int i = 1, j = 0; i <= n; i ++, j ++){
        cout << i + j << " ";
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