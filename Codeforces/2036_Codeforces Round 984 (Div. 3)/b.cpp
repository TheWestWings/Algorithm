#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 10;
 
int a[N];
 
void solve(){
    int n, k;
 
    cin >> n >> k;
    memset(a, 0, sizeof a);
 
    for(int i = 0; i < k; i ++){
        int x, p;
        cin >> x >> p;
 
        a[x] += p;
    }
    
    sort(a, a + k + 1, greater<int>());
 
    int ans = 0;
 
    for(int i = 0; i < min(n, k + 1); i ++){
        ans += a[i];
    }
 
    cout << ans  << endl;
}
 
int main(){
    int t;
    cin >> t;
 
    while(t --){
        solve();
    }
}