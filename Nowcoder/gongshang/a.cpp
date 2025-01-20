#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10;

int a[N];

int main(){
    int n;
    cin >> n;

    int ans = 0;

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    sort(a, a + n);
    

    for(int i = 0; i < n; i ++){
        // cout << n - i << " " << a[(n - i + 1) / 2 - 1 + i] << endl;
        ans = max(ans, (n - i) + a[(n - i + 1) / 2 - 1 + i]);
    }
    cout << ans << endl;
}