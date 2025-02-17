#include <bits/stdc++.h>

using namespace std;

void solve(){
    string x;
    cin >> x;

    int n = x.size();

    // if(x[0] == 1) cout << 2 << "0" * (n - 1) << endl;
    // else cout << "1" << "0" * n << endl;

    if(x[0] == '1') cout << 2;
    else if(x[0] == '2') cout << 3;
    else if(x[0] == '3') cout << 5;
    else if(x[0] == '4') cout << 7;
    if(x[0] == '5') cout << 7;
    else if(x[0] == '6') cout << 11;
    else if(x[0] == '7') cout << 11;
    else if(x[0] == '8') cout << 11;
    else if(x[0] == '9') cout << 11;
    for(int i = 1; i < n; i ++){
        cout << 0;
    }
    cout << endl;
}

int main(){
    int t = 1;
    cin >> t;

    while(t --){
        solve();
    }
}