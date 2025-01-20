#include <bits/stdc++.h>

using namespace std;

void solve(){
    string str;
    cin >> str;

    int n = str.size();

    for(int i = 0; i < n - 1; i ++){
        if(str[i] == str[i + 1]){
            cout << str[i] << str[i + 1] << endl;
            return ;
        }
        if(i + 2 < n && str[i] != str[i + 1] && str[i + 1] != str[i + 2] && str[i] != str[i + 2]){
            cout << str[i] << str[i + 1] << str[i + 2] << endl;
            return ;
        }
    }
    cout << -1 << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}