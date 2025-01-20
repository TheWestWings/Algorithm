#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int N = 2e5 + 10;

pii a[N];

int main(){
    ll n, m;

    cin >> n >> m;


    ll s = 0;
    for(int i = 0; i < m; i ++){
        cin >> a[i].x;
    }

    for(int i = 0; i < m; i ++){
        cin >> a[i].y;
        s += a[i].y;
    }
    if(s != n){
        cout << -1 << endl;
        return 0;
    }

    sort(a, a + m);

    // for(int i = 0; i < m; i ++){
    //     cout << a[i].x << " ";
    // }
    // cout << endl;

    ll ans = 0;
    for(int i = 0; i < m - 1; i ++){
        // cout << a[i + 1].x << " " << a[i].x << " " << a[i].y << endl;
        if(a[i + 1].x - a[i].x - 1 >= a[i].y){
            cout << -1 << endl;
            return 0;
        }
        else if(a[i].y > 1){
            ans += ((a[i].y - 1) + (a[i].y - (a[i + 1].x - a[i].x))) * (a[i + 1].x - a[i].x) / 2;
            a[i + 1].y += a[i].y - (a[i + 1].x - a[i].x);
        }
    }
    
    // cout << a[m - 1].y << " " << n - a[m - 1].x + 1 << endl;
    if(a[m - 1].y != n - a[m - 1].x + 1){
        cout << - 1 << endl;
        return 0;
    }
    cout << ans + ((a[m - 1].y - 1) + 1) * (n - a[m - 1].x) / 2 << endl;
    
}