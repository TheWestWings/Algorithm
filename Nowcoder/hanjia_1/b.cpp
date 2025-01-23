#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    bool flag = false;

    map<int, int> mp;
    for(int i = 0; i < n - 1; i ++){
        int u, v;
        cin >> u >> v;

        mp[u] ++;
        mp[v] ++;
    }

    vector<int> ans;
    for(auto item : mp){
        if(item.second == 1){
            ans.push_back(item.first);
        }
        // cout << item.first << " " << item.second << endl;
        if(item.second > 2){
            flag = true;
        }
    }

    if(flag){
        cout << -1 << endl;
    }
    else{
        for(int i = 0; i < 2; i ++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}