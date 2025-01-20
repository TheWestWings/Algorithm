#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){   
    int n;
    cin >> n;
    
    string colors;
    cin >> colors;
    
    vector<ll> t(n);
    for(auto &x : t) cin >> x;
    

    vector<vector<ll>> s(3, vector<ll>(n+1, 0));
    for(int c=0; c<3; c++){
        for(int i=1; i<=n; i++){
            s[c][i] = s[c][i-1] + ((colors[i-1]-'0') != c ? t[i-1] : 0);
        }
    }
    

    vector<vector<int>> st;
    st.push_back({0, 1, 2});
    st.push_back({0, 2, 1});
    st.push_back({1, 0, 2});
    st.push_back({1, 2, 0});
    st.push_back({2, 0, 1});
    st.push_back({2, 1, 0});
    
    ll ans = LLONG_MAX;
    for(auto p: st){
        int c1 = p[0], c2 = p[1], c3 = p[2];
        
        ll mna = LLONG_MAX;
        ll mnab = LLONG_MAX;
        for(int i = 0; i <= n; i ++){
            ll a = s[c1][i] - s[c2][i];
            mna = min(mna, a);
            ll b = s[c2][i] - s[c3][i];
            mnab = min(mnab, b + mna);
        }
        
        ans = min(ans, mnab + s[c3][n]);
    }
    cout << ans << endl;
}