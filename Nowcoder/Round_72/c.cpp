#include <bits/stdc++.h>

using namespace std;


void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    string ans = "";
    if (k == 0 && a != 0 && b != 0)
    {
        cout << -1 << endl;
        return;
    }
    if (k > 2 * min(a, b) || k > a + b - 1)
    {
        cout << -1 << endl;
        return;
    }
    int f = 0;
    if (a > b) f = 1;
    int lst = 0;
    for (int i = 1; i <= k; i++)
    {
        if ((f + i) & 1)
        {
            ans += '1';
            b--;
            lst = 1;
        }
        else
        {
            ans += '0';
            a--;
            lst = 0;
        }
    }
    if (lst == 0)
    {
        while (a--) ans += '0';
        while (b--) ans += '1';
    }
    else
    {
        while (b--) ans += '1';
        while (a--) ans += '0';
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --) solve();
}