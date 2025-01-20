#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    string str;
    cin >> str;
    // cout << str;

    map<char, int> mp;
    for(int i = 0; i < str.size(); i ++){
        mp[str[i]] ++;
    }
    

    int cmx = -1;
    int mx = -1;
    int cmn = 'a';
    int mn = 0x3f3f3f3f;
    for(auto t: mp){
        // cout << t.first << " " << t.second << endl;
        if(t.second > mx){
            cmx = t.first - 'a';
            mx = t.second;
        }
        if(t.second <= mn){
            cmn = t.first - 'a';
            mn = t.second;
        }
    }
    // cout << char(cmx + 'a') << endl;
    
    int cnt = 1;
    for(int i = 0; i < n; i ++){
        // cout << str[i] - 'a' << " " << cmn << " " << cmx << endl;
        if(cnt == 1 && str[i] - 'a' == cmn){
            // cout << "p" << endl;
            cout << char(cmx + 'a');
            cnt --;
            continue;
        }
        cout << str[i];
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