#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;

void solve(int n){
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        int cnt = 0;
        for(int j = 1; j <= i; j ++){
            if(i % j == 0){
                cnt ++;
            }
        }
        
        if(cnt == 9){
            ans ++;
        }
    }
    if(mp[ans] == 0){
        cout << n << " " << ans << " " << sqrt(n) << " " << sqrt(sqrt(n))  << endl;
        mp[ans] = n;
    }
    // cout << n << " " << ans << endl;
}

int main(){
    int t = 500
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ;
    for(int i = 1; i <= t; i ++){
        solve(i);
    }
}