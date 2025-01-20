#include <bits/stdc++.h>

using namespace std;

const int N = 110;

// char a[N];

int main(){
    int n, k;
    cin >> n >> k;
    // cout << n << " " << k << endl;

    string a;
    cin >> a;
    // cout << a << endl;

    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; i ++){
        // cout << a[i] << endl;
        if(a[i] == 'O'){
            cnt ++;
        }
        else{
            cnt = 0;
        }
        // cout << cnt << endl;
        if(cnt >= k){
            ans ++;
            cnt = 0;
        }
    }
    cout << ans << endl;
}