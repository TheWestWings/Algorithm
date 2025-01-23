#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    if(n == m){
        cout << "NO" << endl;
        return;
    }            

    int x = n - m;
    if(x > 26){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(int i = 0, j = 0; i < n; i ++){
        cout << char('a' + j);
        j ++;
        j %= x;
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