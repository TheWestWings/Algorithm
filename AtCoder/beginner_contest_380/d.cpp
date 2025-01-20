#include <bits/stdc++.h>

using namespace std;

const int N = 64;
typedef long long ll;

ll a[N];

int main(){
    string str;
    cin >> str;
    int n = str.size();

    a[1] = n;
    int len = 0, i;
    for(i = 2; a[i - 1] < 1e18; i ++){
        a[i] = a[i - 1] * 2;
    }
    len = i - 1;
    // for(int i = 0; i < N ; i ++){
    //     cout << a[i] << " ";
    // }
    int q;
    cin >> q;

    while(q --){
        ll k;
        cin >> k;
        ll t = k;

        ll ans = 0;
        ll i = len;
        while(i >= 1){
            // 
            if(k > a[i]){
                // cout << a[i] << " " << k << " " << i << endl;
                k -= a[i];
                ans ++;
            }
            i --;
        }
        // cout << ans << endl;
        if(ans % 2 == 0){
            cout << char(str[(t - 1) % n]) << " ";
        }
        else{
            if(str[(t - 1) % n] >= 'a' && str[(t - 1) % n] <= 'z'){ 
                cout << char(str[(t - 1) % n] - 'a' + 'A') << " ";
            }
            else{
                cout << char(str[(t - 1) % n] - 'A' + 'a') << " ";
            }
        }

    }
}