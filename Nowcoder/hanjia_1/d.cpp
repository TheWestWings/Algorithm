#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N];

void solve(){
    int n;
    cin >> n;

    int cnt = 0;
    map<int, int> mp;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        mp[a[i]] ++;
        if(mp[a[i]] == 1){
            cnt ++;
        }
    }

    int tmp = mp[a[0]];
    for(auto item : mp){
        if(item.second != tmp){
            cout << "No" << endl;
            return;
        }
    }
    if(n % 2 == 0 && cnt == 2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}