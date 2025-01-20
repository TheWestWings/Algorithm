#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int n1 = n, n2 = n;
    int ans = 0;
    if(n1 > a){
        ans += a;
        n1 -= a;
    }
    else{
        ans += n1;
        n1 = 0;
    }
    if(n2 > b){
        ans += b;
        n2 -= b;
    }
    else{
        ans += n2;
        n2 = 0;
    }

    ans += min(n1 + n2, c);
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}