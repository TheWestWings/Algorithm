#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int a[N];

void solve(){
    int n;
    cin >> n;

    map<int, int> mp;
    int mx = 0, mxnum = 0;
    vector<int> v;
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        // v.push_back(a[i]);
        mp[a[i]] ++;
        if(mp[a[i]] == 1){
            cout << a[i] << " ";
            cnt ++;
        }
    }

    for(int i = 1; i <= n; i ++){
        if(mp[i] == 0){
            cout << i << " ";
            cnt ++;
        }
        if(cnt == n){
            break;
        }
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