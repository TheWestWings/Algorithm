#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int a[N];

void solve(){
    int n;
    cin >> n;

    int ji = 0, ou = 0;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        if(a[i] % 2 == 0) ou ++;
        else ji ++;
    }

    if(ou != 0) cout << 1 + ji << endl;
    else cout << ji - 1 << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --) solve();
}