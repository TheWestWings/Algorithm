#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

void solve(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    stack<int> s;
    vector<int> f(n + 1, -1);
    for(int i = 0; i < n; i ++){
        while(!s.empty() && a[s.top()] > a[i]){
            f[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    
    vector<int> ans;
    int mn = 0x3f3f3f3f;
    map<int, int> mp;
    for(int i = 0; i < n; i ++){
        if(f[i] != -1){
            mp[a[i]] ++;
            mn = min(mn, a[i]);
        }
        else if(a[i] - mn >= 2){
            mp[a[i]] ++;
        }
        else{
            ans.push_back(a[i]);
        }
    }

    for(auto t: mp){
        while(t.second --){
            ans.push_back(t.first + 1);
        }
    }

    for(auto x : ans){
        cout << x << " ";
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