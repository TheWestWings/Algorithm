#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, x;
    cin >> n >> k >> x;

    int r1 = x * n;
    int r2 = x * (n + 1);
    if(x + k - 1 < r1 || x + k + x - 1 >= r2){
        cout << -1 << endl;
        return 0;
    }

    if(k == x) cout << x << " " << x + k - 1<< endl;
    else cout << x + k << " " << x + 2 * k - 1 << endl;
}