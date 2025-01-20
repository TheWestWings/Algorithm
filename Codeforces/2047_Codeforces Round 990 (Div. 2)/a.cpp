#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int a[N], s[N];

void solve(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    // for(int i = 1; i <= n; i ++){
    //     cout << s[i] <<" ";
    // }
    // cout << endl;

    int ans = 0;
    for(int i = 1; i <= n; i ++){
        if(int(sqrt(s[i])) == sqrt(s[i]) && int(sqrt(s[i])) % 2 != 0){
            ans ++;
        } 
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}