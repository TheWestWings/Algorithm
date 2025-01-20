#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N];
int b[N];
int c[N];

int main(){
    int n, x, y, z, t;
    cin >> n >> x >> y >> z >> t;


    for(int i = 0; i < n; i ++){
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
    }

    a[n] = x;
    b[n] = y;
    c[n] = z;
    t += z;

    int ans = 0;
    for(int i = 0; i <= n; i ++){
        if(a[i] + b[i] > ans && c[i] <= t){
            ans = a[i] + b[i];
        }
    }
    cout << ans << endl;
}