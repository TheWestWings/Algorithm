#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin >> str;
    
    int n = str.size();

    map<char, int> mp;
    // int cnt = 0, ans = 0;
    // for(int i = 0; i < n; i ++){
    //     if(mp[str[i]] == 0){
    //         mp[str[i]] = 1;
    //         cnt ++;
    //     }
    //     else{
    //         mp.clear();
    //         ans = max(ans, cnt);
    //         cnt = 1;
    //         mp[str[i]] = 1;
    //     }
    // }
    // ans = max(ans, cnt);

    for(int i = 0; i < n; i ++){
        mp[str[i]] ++;
    }

    int ans = 0;
    cout << mp.size() << endl;
    // cout << ans << endl;
}