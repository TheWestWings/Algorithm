#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    int ans = 0, ansi = -1;
    vector<string> v;
    for(int i = 0; i < n; i ++){
        string str;
        cin >> str;
        v.push_back(str); 
    }

    for(int i = 0; i < n; i ++){
        int t = v[i].size();
        // cout << t << " " << m << endl;
        if(ans + t > m){
            break;
        }        
        ans += t;
        ansi = i;
    }
    if(ansi == -1) cout << 0 << endl;
    
    else cout << ansi + 1 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}