#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, d;
    cin >> n >> d;

    string str;
    cin >> str;

    int cnt = 0;
    for(int i = 0; i < n; i ++){
        if(str[i] == '.'){
            cnt ++;
        }
    }
    cout << cnt + d << endl;

}

int main(){
    int t;
    // cin >> t;
    t = 1;

    while(t --){
        solve();
    }
}