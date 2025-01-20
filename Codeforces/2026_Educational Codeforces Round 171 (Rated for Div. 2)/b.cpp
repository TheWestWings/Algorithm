#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
typedef long long LL;

LL a[N];
int n;

bool check(LL x){
    int cnt = 0;
    for(int i = 2; i <= n + 1; i += 2){
        if(a[i] - a[i - 1] > x || i == n + 1){
            cnt ++;
            i --;
        }
    }
    if(cnt > 1) return false;
    // else if(cnt > 0 && n % 2 == 0) return false;
    return true;
}

void solve(){
    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    if(n == 1){
        cout << 1 << endl;
        return ;
    }
    
    LL l = 0, r = 1e18;
    while(l < r){
        LL mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << endl;

}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}