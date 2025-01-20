#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n, m, r, c;
    cin >> n >> m >> r >> c;

    cout << m - c + (n - r) * (m - 1) + (n - r) * m << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --) solve();
}