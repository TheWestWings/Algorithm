#include <bits/stdc++.h>    

using namespace std;

void solve(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int t1 = n - a;
    // if(a > 0 && (b == 0 || c == 0)){
    //     cout << "No" << endl;
    //     return;
    // }

    if(a == 0 && b == 0 && c == 0){
        cout << "No" << endl;
        return;
    }


    if(a + b + c == n){
        cout << "Yes" << endl;
        return;
    }

    if(a + b + c <= 2 * n && a + b + c >= n){
        cout << "Yes" << endl;
        return;
    }
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}