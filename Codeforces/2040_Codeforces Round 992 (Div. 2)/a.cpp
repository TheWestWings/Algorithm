#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int a[N];

void solve(){
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i ++){
        bool flag = true;
        for(int j = 1; j <= n; j ++){
            if(i == j) continue;
            // cout << a[i] << " " << a[j] << endl;
            if(abs(a[i] - a[j]) % k == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
            cout << i << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}