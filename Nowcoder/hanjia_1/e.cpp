#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10;

int a[N];
int n;

int get(int x1, int x2){
    int ans = 0;
    for(int i = 0; i < n / 2; i ++){
        ans += abs(a[i] - x1);
    }

    for(int i = n / 2; i < n; i ++){
        ans += abs(a[i] - x2);
    }

    if(x1 == x2){
        return ans + n / 2;
    }
    else{
        return ans;
    }
}

void solve(){
    
    cin >> n;
    
    map<int, int> mp;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    sort(a, a + n);

    vector<int> v1(a, a + n / 2), v2(a + n / 2, a + n);
    int x1 = v1[n / 4], x2 = v2[n / 4];
    int ans = 0x3f3f3f3f3f3f3f3f;
    for(int i = -1; i <= 1; i ++){
        for(int j = -1; j <= 1; j ++){
            ans = min(ans, get(x1 + i, x2 + j));
        }
    }
    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}