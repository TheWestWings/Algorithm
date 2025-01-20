#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main(){
    int n = 7;

    int ans = 1e9 + 7;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ans = min(ans, a[i]);
    }

    cout << ans << endl;
}