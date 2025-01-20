#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10;

int a[N];
int dp[N];

signed main(){
    int n, x, y;
    cin >> n >> x >> y;

    for(int i = 0; i < n; i ++){
        int c;
        scanf("%1d", &c);
        a[i] = c;
    }

    // int last_1 = -1, last_0 = -1;
    dp[0] = 0;
    int i;
    for(i = 1; i < n; i ++){
        // cout << a[i] << " " << a[0] << endl;
        if(a[i] == a[0]){
            dp[i] = dp[i - 1] + x;
        }
        else{
            dp[i] = dp[i - 1] + y;
            break;
        }
    }
    i ++;
    for(i; i < n; i ++){
        int t1 = i, t2 = i;
        for(int j = i - 1; j >= 0; j --){
            if(a[i] != a[j]){
                t1 = j;
                break;
            }
        }
        for(int j = i - 1; j >= 0; j --){
            if(a[i] == a[j]){
                t2 = j;
                break;
            }
        }
        if(t1 < t2) dp[i] = dp[t2] + x;
        else dp[i] = min(dp[t1] + y, dp[t2] + x);
    }

    for(int i = 0; i < n; i ++){
        cout << dp[i] << " ";
    }

    cout << dp[n - 1] << endl;
}