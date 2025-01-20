#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e6  + 10;

int a[N];

signed main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    if(n == 1){
        cout << "0.00" << endl;
        return;
    }
    sort(a, a + n);

    double ans = a[0] / 2.0 + a[1] / 2.0;
    for(int i = 2; i < n; i ++){
        ans += a[i];
    }
    cout << ans << endl;
}