#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int a[2][N], s[2 * N];

void solve(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> a[0][i];
        s[i] = a[0][i];
    }
    for(int i = 0; i < n; i ++){
        cin >> a[1][i];
        s[i + n] = a[1][i];
    }

    // sort(s, s + 2 * n, greater<int>());
    int ans = 0;
    vector<int> v;
    for(int i = 0; i < n; i ++){
        ans += max(a[0][i], a[1][i]);
        v.push_back(min(a[0][i], a[1][i]));
    }
    sort(v.begin(), v.end(), greater<int>());
    ans += v[0];
    
    cout << ans << endl;

    
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}