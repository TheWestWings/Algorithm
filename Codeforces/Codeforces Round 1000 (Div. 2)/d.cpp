#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 10;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < m; i ++) cin >> b[i];

    if (n == 1 && m == 1){
        cout << 0 << endl;
        return;
    }

    if(m > n){
        swap(n, m);
        swap(a, b);
    }

    int k = 0;
    if(n >= m * 2){
        k = m;
    }
    else {
        k = (n + m) / 3;
    }
    cout << k << endl;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<pair<int, int>> t;
    for(int i = 0; i < n / 2; i ++){
        t.push_back({a[n - i - 1] - a[i], 1});
    }
    for(int i = 0; i < m / 2; i ++){
        t.push_back({b[m - i - 1] - b[i], 2});
    }

    sort(t.begin(), t.end(), greater<pair<int, int>>());
    
    // for(auto [d, id] : t){
    //     cout << d << " ";
    // }
    // cout << endl;

    int j = 0;
    int cnt1 = 0, cnt2 = 0, ans = 0;
    multiset<int> s1, s2;
    for(int i = 0; i < k; i ++){
        while(1){
            auto [d, id] = t[j ++];
            if(id == 1){
                cnt1 += 2;
                cnt2 ++;
                s1.insert(d);
                ans += d;
            }
            else {
                cnt2 += 2;
                cnt1 ++;
                s2.insert(d);
                ans += d;
            }
            if(cnt1 <= n && cnt2 <= m){
                cout << ans << " ";
                break;
            }
            if(cnt1 > n){
                cnt1 -= 2;
                cnt2 --;                                                        
                ans -= *s1.begin();
                s1.erase(s1.find(*s1.begin()));
            }
            else{
                cnt2 -= 2;
                cnt1 --;
                ans -= *s2.begin();
                s2.erase(s2.find(*s2.begin()));

            }
        }
    }
    cout << endl;
}

signed main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}