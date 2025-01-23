#include <bits/stdc++.h>

using namespace std;

const int N = 10;

bool st[N];

vector<int> ans(N);

void dfs(int t){
    if(t == 8){
        for(int i = 0; i < 8; i ++){
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= 8; i ++){
        if(!st[i]){
            st[i] = true;
            // cout << t << endl;
            ans[t] = i;
            dfs(t + 1);
            st[i] = false;
        }
    }
}

int main(){
    dfs(0);
}