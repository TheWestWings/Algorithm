#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 10;

int a[N];

signed main(){
    int n, m;
    cin >> n >> m;

    while(m --){
        int l, r;
        cin >> l >> r;
        a[l] ++;
        a[r + 1] --;
        a[r + 1] -= (r - l + 1);
        a[r + 2] += (r - l + 1);
        
    }

    for(int i = 1; i <= n; i ++){
        cout << a[i] << " ";
    }
    cout << endl;

    for(int i = 1; i <= n; i ++){
        a[i] += a[i - 1];
    }

    for(int i = 1; i <= n; i ++){
        cout << a[i] << " ";
    }
    cout << endl;

    for(int i = 1; i <= n; i ++){
        a[i] += a[i - 1];
    }

    for(int i = 1; i <= n; i ++){
        cout << a[i] << " ";
    }
}