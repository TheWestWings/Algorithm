#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    cin >> n;

    int last_t = 0, ans = 0;
    for(int i = 0; i < n; i ++){
        int t, v;
        cin >> t >> v;
        if(ans > 0){
            ans -= t - last_t;
        }
        if(ans < 0){
            ans = 0;
        }
        ans += v;
        last_t = t;
    }

    cout << ans << endl;
}