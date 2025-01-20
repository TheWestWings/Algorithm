#include <bits/stdc++.h>

using namespace std;

const int N = 1100;

// int dp[N][100000];
int a[N];

int main(){
    int n;
    cin >> n;

    int s = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s += a[i];
    }

    if(s % 2 != 0){
        cout << -1 << endl;
        return 0;
    }
    s /= 2;
    vector<vector<int>> dp(n + 1 , vector<int>(s + 1 , 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++){
        dp[i] = dp[i - 1];
        for(int j = 1; j <= s; j++){
            // dp[i][j] = dp[i - 1][j];
            if(j - a[i] >= 0){
                dp[i][j] |= dp[i - 1][j - a[i]];
            }
        }
    }

    if(dp[n][s] == 0){
        cout << -1 << endl;
        return 0;
    }
    // cout << dp[n][s] << endl;

    vector<int> u, v;
    int cnt = 0;
    for(int i = n; i >= 1; i--){
        if(dp[i][s] == dp[i - 1][s]){
            v.push_back(i);
        }
        else{
            u.push_back(i);
            s -= a[i];
            cnt += a[i];
        }
    }

    cout << cnt << endl;
    // for(auto x : u){
    //     cout << x << " ";
    // }
    // cout << endl;
    // for(auto x : v){
    //     cout << x << " ";
    // }
    // cout << endl;
    for(auto x : u){
        while(a[x]){
            for(auto y : v){
                while(a[x] && a[y]){
                    cout << x << " " << y << endl;
                    a[x]--;
                    a[y]--;
                }
            }
        }
    }
    
}