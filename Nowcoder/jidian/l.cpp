#include <bits/stdc++.h>
#define int long long

using namespace std;

int mxi = 0;
int n;
int cnt = 0;
string str;

bool check(int x){
    if((cnt - 1) * x > n - cnt) return false;
    else{
        int t = 0;
        for(int i = n - 1; i >= n - x - 1; i --){
            // if(x == 1) cout << "str[i]" << str[i] << endl;
            if(str[i] == '1'){
                t ++;             
            }
        }
        if(t >= 2 && x == 1){
            // cout << "false" << endl;
        }
        if(t >= 2) return false; 
    }
    // cout << x << "x" << endl;
    return true;
}

signed main(){ 
    cin >> n;
    
    cin >> str;
   
    for(int i = 0; i < n; i ++){
        if(str[i] == '1'){
            mxi = i;
            cnt ++;
        } 
    }

    if(cnt == 1 || cnt == 0){
        cout << "2147483647" << endl;
        return 0 ;
    }

    int l = 0, r = 2147483647;
    int ans = 0;
    while(l < r){
        int mid = l + r >> 1;
        if(!check(mid)) r = mid;
        else{
            ans = mid;
            l = mid + 1;
        }
    }

    cout << ans;
}