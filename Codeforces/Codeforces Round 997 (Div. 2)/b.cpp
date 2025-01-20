#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n));
    vector<pair<int, int>> num;
    vector<int> ans(n);
    for(int i = 0; i < n; i ++){
        string str;
        cin >> str;
        int s = 0;
        for(int j = i; j < n; j ++){
            g[i][j] = str[j] - '0';
            s += g[i][j];
        }
        // cout << s << endl;
        for(int j = n - 1; j >= 0; j --){
            if(ans[j] == 0 && s == 0){
                ans[j] = i + 1;
                break;
            }
            if(ans[j] == 0) s --;
        }
        
        // num.push_back({i + 1, s});
    }

    // sort(num.begin(), num.end(), [](pair<int, int> a, pair<int, int> b){
    //     if(a.second == b.second){
    //         return a.first > b.first;
    //     }
    //     return a.second < b.second;
    // });

    for(int i = 0; i < n; i ++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}