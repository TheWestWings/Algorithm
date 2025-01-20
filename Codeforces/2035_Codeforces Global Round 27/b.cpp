#include <bits/stdc++.h>

using namespace std;

bool st[100];
typedef long long ll;

bool check(ll x){
    int cnt = 0;
    while(x){
        
        int t = x % 10;
        cnt ++;
        x /= 10;
        // cout << "x" << x << endl;
        // cout << "T " << t << endl;
        if(t == 3 || t == 6){
            continue;
        }   
        if(x == 0 && !st[cnt]){
            st[cnt] = true;
            return true;
        }
        // cout << t << endl;
        return false;
            
    }
            // cout << cnt << endl;

    if(!st[cnt]) {
        st[cnt] = true;
        return true;
    }
    return false;
}

int main(){
    for(ll i = 0; i < 1e13; i ++){
        ll a = 66 * i;
        // cout << a << endl;
        if(check(a)){
            cout << a << endl;
        }
    }

}