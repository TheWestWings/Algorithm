#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin >> s;

    int n = s.size();

    ll ans = 1e10 + 1;
    for(int i = 0; i < n; i ++){
        ll t = 0;
        for(int j = i ; j < i + n; j ++){
            t = t * 10 + s[j % n] - '0';
        }
        ans = min(ans, t);
    }

    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve()
;    }
}