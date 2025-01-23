#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    string str;
    cin >> str;

    map<char, int> mp;

    // for(auto c : str){
    //     mp[c] ++;
    // }

    mp[str[0]] ++;
    int ans = 0;
    for(int i = 1; i < n; i ++){
        if(mp[str[i]] != 0){
            ans = max(ans, n - i);
        }
        mp[str[i]] ++;
    }
    // cout << ans << endl;

    mp.clear();

    mp[str[n - 1]] ++;
    for(int i = n - 2; i >= 1; i --){
        if(mp[str[i]] != 0){
            ans = max(ans, i + 1);
        }
        mp[str[i]] ++;
    }

    cout << ans << endl;
}