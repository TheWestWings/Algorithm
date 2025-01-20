#include <bits/stdc++.h>
#define int long long

using namespace std;

int qmi(int a, int b){
    int res = 1;
    while(b){
        if(b & 1){
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

signed main(){
    int n;
    cin >> n;

    if(n <= 10){
        cout << n - 1 << endl;
        return 0;
    }

    if(n < 20){
        cout << (n - 10) * 11 << endl;
        return 0;
    }
    if(n == 20){
        cout << 101 << endl;
        return 0;
    }
    

    int cnt = 0;
    int t = n;
    while(t){
        t /= 10;
        cnt ++;
    }
    if(n > 11 * qmi(10, cnt - 2)){
        int ans = n - qmi(10, cnt - 1);
        cout << ans;
        // ans /= 10;
        while(ans){
            cout << ans % 10;
            ans /= 10;
        }
        // cout << n - qmi(10, cnt - 1) << endl;
        // return 0;
    }


    else{
        int ans = n - qmi(10, cnt - 2);
        cout << ans;
        ans /= 10;
        while(ans){
            cout << ans % 10;
            ans /= 10;
        }
    } 
    // cout << n - qmi(10, cnt - 2) << endl;
    
}