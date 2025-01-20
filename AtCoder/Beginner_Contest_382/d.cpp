#include <bits/stdc++.h>

using namespace std;

// const int N = 2e5 + 10;

int n, m;
vector<vector<int>> res; 
vector<int> ans(20, 0);

void dfs(int t, int x){
    // cout << t << " " << x << " " << m << endl;
    // if(x > m){
    //     return;
    // }
    if(t == n){
        // for(int i = 0; i < n; i ++){
        //     cout << ans[i] << " ";
        // }
        // cout << endl;
        res.push_back(ans);
        // ans.pop_back();
        // cout << x + 10 << endl;
        return;
    }
    
    for(int i = x; i <= m - (n - t - 1) * 10; i ++){
        // cout << i << " ";
        ans[t] = i;
        
        dfs(t + 1, i + 10);
        // ans.pop_back();
    }
}

int main(){
    
    cin >> n >> m;

    dfs(0, 1);

    cout << res.size() << endl;

    for(int i = 0; i < res.size(); i ++){
        for(int j = 0; j < n; j ++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}