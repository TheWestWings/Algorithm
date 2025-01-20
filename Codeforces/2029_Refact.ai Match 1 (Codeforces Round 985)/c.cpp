#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int a[N];

void solve(){
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i ++){
        scanf("%1d", &a[i]);
        if(a[i] == 0) a[i] = -1;
        // s[i] = s[i - 1] + a[i];
    }

    vector<int> v, s(n + 2);
    for(int i = n; i >= 2; i --){
        s[i] = s[i + 1] + a[i];
        v.push_back(s[i]);
    }
    sort(v.begin(), v.end(), greater<int>());

    // for(auto t: v){
    //     cout << t << " ";
    // }
    // cout << endl;

    int ans = 1, w = 0;
    for(auto t: v){
        w += t;
        ans ++;
        if(w >= k) break;
    }

    cout << (w >= k ? ans: -1) << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}