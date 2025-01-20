#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10;

int a[N];

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

signed main(){
    int n;
    cin >> n;

    int mn = 1e9 + 10;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        mn = min(mn, a[i]);
    }

    int ans = a[0];
    for(int i = 1; i < n; i ++){
        ans = gcd(ans, a[i]);
    }

    cout << ans << endl;
}