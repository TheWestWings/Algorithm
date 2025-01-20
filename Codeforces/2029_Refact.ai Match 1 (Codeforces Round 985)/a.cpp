#include <bits/stdc++.h>

using namespace std;

const int N = 100;

// vector<int> a(N), s(N);

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1), s(n + 1);

    for(int i = 1; i <= n; i ++) cin >> a[i];;

    sort(a.begin() + 1, a.end(), greater<int>());

    for(int i = 1; i <= n; i ++){
        s[i] = s[i - 1] + a[i];
    }

    // for(int i = 1; i <= n; i ++){
    //     cout << s[i] << " ";
    // }
    // cout << endl;

    // cout << k << endl;
    auto u = upper_bound(s.begin() + 1, s.begin() + n + 1, k);
    // cout << distance(s.begin(), u) << " ";
    u --;
    cout << k - *u << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}