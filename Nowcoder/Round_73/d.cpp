#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    int n, k;
    cin >> n >> k;

    string str;
    cin >> str;

    int l = -1;
    for(int i = 0; i < n; i ++){
        if(str[i] == '0'){
            l = i;
            break;
        }
    }
    if(l == -1){
        cout << -1 << endl;
        return 0;
    }
    int cnt0 = 1;
    int cnt1 = 0;
    int ans = 0;
    for(int i = l + 1; i < n; i ++){
        if(str[i] == '1'){
            ans += cnt0;
            cnt1 ++;
        }   
        else{
            cnt0 ++;
        }

        while(l < i && ans > k && l < n){
            if(str[l] == '0'){
                ans -= cnt1;
                cnt0 --;
            }
            else{
                cnt1 --;
            }
            l ++;
        }
        if(ans == k){
            cout << l + 1 << " " << i + 1 << endl;
            return 0;
        }
        // cout << ans << " " << cnt0 << " " << cnt1 << endl;
    }
    cout << -1 << endl;
}