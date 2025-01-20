#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int a[N];

void solve(){
    int n, m, k;

    cin >> n >> m >> k;

    for(int i = 0; i < n; i ++) scanf("%1d", &a[i]);

    int now = 0, ans = 0;
    for(int i = 0; i < n; i ++){
        if(a[i] == 0){
            now ++; 
        }
        else{
            now = 0;
        }
        if(now >= m){
            int j;
            // for(j = i; j - i < k; j ++){
            //     // cout << j << " " << i << " " << m << endl;
            //     a[j] = 1;
            // }
            ans ++;
            now = 0;
            // i = j - 1;
            i = i + k - 1;
        }
    }

    // for(int i = 0; i < n; i ++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}