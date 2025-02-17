#include <bits/stdc++.h>

using namespace std;

void solve(){
    string str;
    cin >> str;

    int cnt = 0;
    int n = str.size();
    for(int i = 0; i < n; i ++){
        if(str[i] == '1'){
            cnt ++;
        }
    }

    cout << cnt << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}