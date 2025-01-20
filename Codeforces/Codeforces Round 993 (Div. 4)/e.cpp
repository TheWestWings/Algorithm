#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    
    ll count = 0;
    ll y = 1;
    
    while(y <= r2){
    
        ll a_x = max((ll)l1, (l2 + y - 1) / y);
        ll b_x = min((ll)r1, r2 / y);
        
        if(a_x <= b_x){
            count += (b_x - a_x + 1);
        }
        
        if(y > r2 / k){
            break;
        }
        y *= k;
    }
    
    cout << count << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}