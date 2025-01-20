#include <bits/stdc++.h>
#define int long long

using namespace std;

int jiecheng(int n){
    if(n == 0) return 1;
    return n * jiecheng(n - 1);
}

signed main(){
    string str;
    cin >> str;
    int n = str.size();

    // if(n == 1){
    //     cout << 1 << endl;
    //     return 0;
    // }

    int ans = 0, cnt = 1;
    for(int i = 1; i < n; i ++){
        if(str[i] != str[i - 1]){
            cnt ++;
        }
        else{
            ans += cnt * (cnt - 1) / 2;
            cnt = 1;
        }
    }
    cout << ans + cnt * (cnt - 1) / 2 << endl;
}