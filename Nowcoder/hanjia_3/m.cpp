#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin >> str;

    map<char, int> mp;
    for(int i = 0; i < str.size(); i++){
        mp[str[i]]++;
    }

    string ans = "nowcoder";
    for(int i = 0; i < ans.size(); i++){
        // cout << ans[i] << " " << mp[ans[i]] << endl;
        if(mp[ans[i]] != 1 && ans[i] != 'o'){
            cout << "I AK IOI" << endl;
            return 0;
        }
        else if(mp[ans[i]] != 2 && ans[i] == 'o'){
            cout << "I AK IOI" << endl;
            return 0;
        }
    }

    cout << "happy new year" << endl;
}