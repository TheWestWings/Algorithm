#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10;

int a[N];
int n;

bool check(int x){
    int x1 = x;
    int x2 = x;
    vector<int> t;
    for(int i = 0; i < n; i ++) t.push_back(max(a[i] - x, 1LL * 0));

    for(int i = 0; i < n - 1; i ++){
        if(x1 > 0 ){        
            int cnt = min({t[i], t[i + 1], x1});  
            t[i] -= cnt;
            t[i + 1] -= cnt;
            x1 -= cnt;
        }
    }
    x2 += x1;
    int s = 0;
    // for(int i = 0; i < n; i ++){
    //     cout << t[i] << " ";
    // }
    // cout << endl;
    for(int i = 0; i < n; i ++) s += t[i];
    // cout << s << " " << x2 << endl;

    if(s <= x2) return true;
    else return false;
}

signed main(){
    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    int l = 0, r = 1e10;
    int ans = 0;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)){
            r = mid;
            ans = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}