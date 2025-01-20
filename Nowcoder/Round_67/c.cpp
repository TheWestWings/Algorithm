#include <bits/stdc++.h>

using namespace std;
typedef long long ll;   

int n;

int check(int x){ 
    if(x == 0) return 1;
    int cnt = 0;
    while(x){
        x /= 10;
        cnt ++;
    }
    // cout << cnt << endl;
    return cnt;
}

int main(){
    int c;
    cin >> n >> c;

    n -= 2;
    n -= check(c);
    ll ans = 0;
    for(int i = 0; i <= c; i ++){
        int t = c - i;
        // cout << check(t) << " " << check(i) << endl;
        if(check(t) + check(i) == n){
            // cout << t << " " << i << endl;
            ans ++;
        }
    }
    cout << ans << endl;
    // cout << check(1111) << endl;
}