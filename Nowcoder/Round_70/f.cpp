#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 10;

int a[N];

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

void solve(){
    int n, k;
    cin >> n >> k;

    int ji = 0, ou = 0;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        if(a[i] % 2 == 1) ji ++;
        else ou ++;
    }

    if(ji != 0 && ou != 0){
        cout << 0 << " " << 0 << endl;
        return;
    }

    if(n == 1){
        cout << k << " " << (1 + k) * k / 2 << endl;
        return;
    }

    int cnt = 0, ans = 0;
     for(int j = 1 ; j <= k ; j ++){
        bool flag = true;
        for(int i = 0; i < n - 1; i ++){
            // cout << gcd(a[i] + j, a[i + 1] + j) << " " << min(a[i] + j, a[i + 1] + j) << endl;
            if(gcd(a[i] + j, a[i + 1] + j) != min(a[i] + j, a[i + 1] + j)){
                flag = false;
                break;
            }
        }
        if(!flag) continue;
        cnt ++;
        ans += j;
    }

    cout << cnt << " " << ans << endl;


}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}