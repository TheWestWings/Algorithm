#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }


    for(int i = 0; i < n - 1; i ++){
        int t = min(a[i], a[i + 1]);
        a[i] -= t;
        a[i + 1] -= t;
    }

    // for(int i = 0; i < n; i ++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    for(int i = 0; i < n - 1; i ++){
        if(a[i] > a[i + 1]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}