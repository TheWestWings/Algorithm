#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd (ll a, ll b) { return b ? gcd (b, a % b) : a; }

int main(){
    ll n, h;
    cin >> n >> h;
    
    while(n --){
        ll x, y, z;
        cin >> x >> y >> z;
        
        ll t =  (h - z) * 2 + z;
        ll ans = gcd(x, gcd(y , t));
//         cout << ans << endl;
        cout << x / ans << " " << y / ans << " " << t / ans << endl;
    }
}