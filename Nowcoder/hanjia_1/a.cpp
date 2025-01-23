#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N];

bool isPrime(int x){
    if(x < 2) return false;
    for(int i = 2; i <= x / i; i ++){
        if(x % i == 0) return false;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;

    bool flag = false;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        if(a[i] == 1){
            flag = true;
        }
    }

    if(flag){
        cout << -1 << endl;
        return;
    }
    // cout << 1e9 + 7 << endl;
    cout << 10000000001 << endl;

}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}