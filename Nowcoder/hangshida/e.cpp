#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int a[N];
int n, x;
map<int, int> mp;

int mex(){
    for(int i = 0; i <= n; i ++){
        if(mp[i] == 0){
            return i;
        }
    }
}

int main(){
    cin >> n >> x;
    
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        mp[a[i]] ++;
    }
    // cout << mex() << endl;

    if(mex() == x){
        cout << 0 << endl;
        return 0;
    }
    if(mex() > x){
        // cout << "1" << endl;
        cout << mp[x] << endl;
        return 0;
    }
    if(mex() < x){
        int ans = 0;
        for(int i = 0; i < x; i ++){
            // cout << i << " " << mp[i] << endl;
            if(mp[i] == 0){
                ans ++;
            }
        }
        if(mp[x] - ans >= 0)
            cout << ans + (mp[x] - ans)  << endl;
        else cout << ans << endl;
    }
}   