#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;

    // int n = str.size();

    int cnt = 0, flag = 0;
    vector<pair<int, int>> v;   
    for(int i = 0; i < n; i ++){
        if(str[i] == '1'){
            cnt ++;
            v.push_back({i + 1, i + 1});
        }
    }

    cout << cnt << endl;
    for(auto p: v){
        cout << p.first << " " << p.second << endl;
    }
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}