#include <bits/stdc++.h>

using namespace std;

void solve(int n){
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        if(n % i == 0){
            ans += i;
        }
    }
    cout << n << " " << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 100;
    for(int i = 1; i <= t; i ++){
        solve(i);
    }
}