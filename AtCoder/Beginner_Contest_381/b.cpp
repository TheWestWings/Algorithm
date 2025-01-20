#include <bits/stdc++.h>

using namespace std;

bool solve(){
    // int n;
    // cin >> n;

    string str;
    cin >> str;

    int n = str.size();

    if(n % 2 != 0) return false;

    map<int, int> mp;
    for(int i = 0; i < n; i ++){
        mp[str[i]] ++;
        if(mp[str[i]] > 2) return false;
    }

    for(auto t : mp){
        if(t.second != 2) return false;
    }

    for(int i = 0; i < n; i += 2){
        if(str[i] != str[i + 1]) return false;
    }
    return true;
}

int main(){
    int t = 1;

    while(t --){
        if(solve()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}