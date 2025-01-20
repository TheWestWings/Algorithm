#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int st[N];

void solve(){
    string str;
    cin >> str;

    int n = str.size();
    memset(st, 0, sizeof st);
    int s = 0;
    for(int i = 0; i < n; i ++){
        s += str[i] - '0';
        st[str[i] - '0'] ++;
    }

    int t = 9 - s % 9;
    if(t == 0){
        cout << "YES" << endl;
        return;
    }

    vector<int> v(5);
    for(int i = 1; i <= 3; i ++){
        v[i] = i * i - i;
    }

    if(t == 1 || t == 3 || t == 5 || t == 7 || t == 9){
        cout << "NO" << endl;
        return;
    }
    if(t == 2 && st[2] >= 1 || st[3] >= 2){
        
    }

    map<int, int> mp;
    int ans = 0;
    for(int i = 1; i <= 3; i ++){
        while(st[i]){
            st[i] --;
            ans = (ans + v[i]) % 9;
            mp[ans] ++;
        }
    }
    if(mp[t]) cout << "YES" << endl;
    else cout << "NO" << endl;

    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}