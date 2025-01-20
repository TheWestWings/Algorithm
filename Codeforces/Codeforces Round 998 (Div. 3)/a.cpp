#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    
    if(a1 + a2 == a4 - a2 && a1 + a2 == a5 - a4 && a5 - a4 == a4 - a2)
        cout << 3 << endl;
    else if(a1 + a2 == a4 - a2 || a1 + a2 == a5 - a4 || a5 - a4 == a4 - a2)
        cout << 2 << endl;
    else
        cout << 1 << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}