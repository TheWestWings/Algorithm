#include <bits/stdc++.h>

using namespace std;

int qmi(int a, int b){
    int res = 1;
    while(b){
        if(b & 1){
            res = (long long)res * a;
        }
        a = (long long)a * a;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n, k;
    cin >> n >> k;

    if(k > qmi(2, n - 1)){
        cout << -1 << endl;
        return;
    }

    while(k){
        int t = qmi(2, n) - k;
        int cnt = 0;
        while(t){
            t >>= 1;
            cnt ++;
        }
        cout << n - cnt + 1<< " ";
        k /= 2;
    }
    cout << endl;

}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}