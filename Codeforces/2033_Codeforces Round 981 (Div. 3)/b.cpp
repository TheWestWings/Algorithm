#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 10;

int a[N];

void solve(){
    int n;
    cin >> n;

    int s = 0;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        s += a[i];
    }

    if(s % n != 0){
        cout << "NO" << endl;
        return;
    }
    
    int t = s / n;
    for(int i = 1; i < n - 1; i ++){
        // if(a[i] == t) continue;
        // if(a[i] < 0 || a[i - 1] < 0 || a[i + 1] < 0){
        //     cout << "NO" << endl;
        //     return;
        // }
        if(a[i - 1] < t){
            a[i + 1] -= t - a[i - 1];
            a[i - 1] = t;
        }
        else if(a[i - 1] > t){
            a[i + 1] += a[i - 1] - t;
            a[i - 1] = t;
        }
        // if(a[i + 1] < 0){
        //     cout << "NO" << endl;
        //     return;
        // }
    }

    for(int i = 0; i < n; i ++){
        if(a[i] != t){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
    
}

signed main(){
    int t;
    cin >> t;

    while(t --) solve();
}