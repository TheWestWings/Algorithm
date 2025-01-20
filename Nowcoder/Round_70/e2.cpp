#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    if(n % 4 == 1){
        cout << 0 << endl;
    }
    else if(n % 4 == 2){
        cout << n + 1 << endl;
    }
    else if(n % 4 == 3){
        cout << 1 << endl;
    }
    else{
        cout << n << endl;
    }
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}