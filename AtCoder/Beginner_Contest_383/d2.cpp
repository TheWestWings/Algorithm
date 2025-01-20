#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 6; i <= sqrt(n); i ++){
        int x = i * i;
        int cnt = 1;
        // cout << i << endl;
        unordered_map<int, int> hash;
        for(int j = 2; j <= i; j ++){
            while(x % j == 0){
                x /= j;
                hash[j] ++;
            }    
        }
        if(x > 1){
            hash[x] ++;
        }
        for(auto [k, v] : hash){
            cnt *= (v + 1);
        }
        if(cnt == 9){
            ans ++;
            cout << i * i << " " << ans << endl;
        }
    }
    cout << ans << endl;
}