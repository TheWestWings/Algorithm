#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int q;
    cin >> q;

    queue<ll> q1;

    ll last = 0;
    while(q --){
        int op;
        cin >> op;
        if(op == 1){
            q1.push(0 - last);
        }
        else if(op == 2){
            ll x;
            cin >> x;
            last += x;
        }
        else{
            ll ans = 0;
            ll h = 0;
            cin >> h;
            ll t = q1.front();
            // cout << "last" << last << endl;
            // cout << t << endl;
            while(t + last >= h && !q1.empty()){
                ans ++;
                q1.pop();
                t = q1.front();
                // cout << t << endl;
            }
            cout << ans << endl;
        }
    }
}