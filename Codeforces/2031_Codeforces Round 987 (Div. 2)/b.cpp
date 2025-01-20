#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int a[N];

bool solve(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i ++){
        if(abs(a[i] - i) >= 2){
            return false;
        }
    }

    return true;
}

int main(){
    int t;
    cin >> t;

    while( t--){
        if(solve()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}