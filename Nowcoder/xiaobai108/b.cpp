#include <bits/stdc++.h>
#define int long long

using namespace std;

map<int, int> mp;   
int cnt = 0;

bool dfs(int sum, int step){
    // cout << sum << " " << step << endl;
    if(step == cnt){
        // cout << sum << endl;
        return sum % 4 == 0;
    }

    for(auto &x : mp){
        if(x.second){
            x.second --;
            if(dfs(sum * 10 + x.first, step + 1)) return true;
            x.second ++;
        }
    }

    return false;
}

void solve(){
    int num;
    cin >> num;
    mp.clear();
    cnt = 0;

    while(num){
        mp[num % 10] ++;
        num /= 10;
        cnt ++;
    }

    if(dfs(0, 0)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}