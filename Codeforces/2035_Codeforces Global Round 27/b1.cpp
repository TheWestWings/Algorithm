#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n == 1 || n == 3) cout << -1 << endl;
    else if(n % 2 == 0){
        for(int i = 0; i < n - 2; i ++){
            cout << "3";
        }
        cout << "66" << endl;
        
    }
    else{
        for(int i = 0; i < n - 5; i ++){
            cout << "3";
        }
        cout << "36366" << endl;
    }
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}