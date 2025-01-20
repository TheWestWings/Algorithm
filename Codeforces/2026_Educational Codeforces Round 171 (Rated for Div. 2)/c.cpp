#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 10;
typedef long long LL;

LL a[N];

void solve(){
    LL n;
    cin >> n;

    for(LL i = 1; i <= n; i ++){
        scanf("%1d", &a[i]);
    }

    LL cnt = 0, k = 1;
    for(LL i = n; i >= k; i --){
        LL j = i - 1;
        while(j >= k && a[j] == 0) j --;
        if(i - 1 == j) {
            // cout << i << " " << j << endl;
            cnt += k;
            k ++;
            continue;
        }
        // cout << (j + 1 + i - 1) * (i - j - 1) / 2 << endl;
        // cout << i << " " << j << endl;
        cnt += (j + 1 + i - 1) * (i - j - 1) / 2;
        i = j + 1;
    }
    cout << cnt << endl;
}

int main(){
    int t;
    cin >> t;
    while(t --){
        solve();
    }
}