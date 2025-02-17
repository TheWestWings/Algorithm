#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int a[N];

void solve(){
    int n;
    cin >> n;

    int mn = 1e9 + 10;

    for(int i = 0; i < n; i ++){
        cin >> a[i];
        mn = min(mn, a[i]);
    }

    for(int i = 0; i < n; i ++){
        // cout << i * 2 << " " << n - 1 - i + 1 << " " << a[i] << endl;
        if(a[i] <= max(i * 2, (n - 1 - i) * 2)){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}   

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}