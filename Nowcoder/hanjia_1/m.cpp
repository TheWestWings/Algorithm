#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10;
typedef pair<int, int> PII;

PII b[N];
int a[N];

signed main(){
    int n;
    cin >> n;

    multiset<int> s;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        s.insert(a[i]);
        b[i] = {a[i], i};
    }

    sort(b, b + n);
    auto [l, r] = b[0];
    s.erase(s.find(l));
    s.insert(l * 2);
    l = r;

    int ans = *s.rbegin() - *s.begin();
    for(auto [_, i] : b){
        if(i >= l && i <= r) continue;
        while(i < l){
            l --;
            s.erase(s.find(a[l]));
            s.insert(a[l] * 2);
            ans = min(ans, *s.rbegin() - *s.begin());
        }
        while(i > r){
            r ++;
            s.erase(s.find(a[r]));
            s.insert(a[r] * 2);
            ans = min(ans, *s.rbegin() - *s.begin());
        }
    }

    cout << ans << endl;
}