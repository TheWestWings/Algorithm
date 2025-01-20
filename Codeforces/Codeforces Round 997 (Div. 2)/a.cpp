#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int x[N], y[N];

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i ++){
        cin >> x[i] >> y[i];
    }
    
    int sx = 0, sy = 0;
    for(int i = 1; i < n; i ++){
        sx += x[i], sy += y[i];
    }

    sx += m, sy += m;
    cout << sx + sy + sx + sy << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}