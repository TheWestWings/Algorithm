#include <bits/stdc++.h>

using namespace std;

void solve(int n){
    vector<int> ans;
    for(int i = 1; i <= n; i ++){
        ans.push_back(n % i);
    }
    // sort(ans.begin(), ans.end());
    // reverse(ans.begin(), ans.end());

    int s = 0;
    for(int i = 0; i < ans.size(); i++){
        
        cout << ans[i] << " ";
    }
    // cout << endl;
    cout << "----------------" << n << endl;
}

int main(){
    for(int i = 1; i <= 30; i ++){
        solve(i);
        
    }
}