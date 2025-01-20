#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int a[N];

int main(){
    int n;
    cin >> n;

    int s = 0;
    int mx = 0, mn = 1e9;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        s += a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    // int avg = s / n;

    // int ans1 = 0, ans2 = 0;
    // for(int i = 0; i < n; i ++){
    //     if(a[i] > avg){
    //         ans1 = max(ans1, a[i] - avg);
    //     }
    //     else{
    //         ans2 = max(ans2, avg - a[i]);
    //     }
    // }

    cout << mx - mn << " " << mx - (mx - mn) / 2 << endl;

    
}