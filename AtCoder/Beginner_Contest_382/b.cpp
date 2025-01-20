#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, d;
    cin >> n >> d;

    string str;
    cin >> str;

    for(int i = n - 1; i >= 0; i --){
        if(str[i] == '@' && d > 0){
            str[i] = '.';
            d --;
        }
    }

    cout << str << endl;
}

int main(){
    int t;
    // cin >> t;
    t = 1;

    while(t --){
        solve();
    }
}