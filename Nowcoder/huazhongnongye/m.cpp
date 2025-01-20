#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int a[N];

int main(){
    int n;
    cin >> n;

    int t1 = 0, t2 = 0;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        if(a[i] == 1){
            t1 ++;
        }
        else{
            t2 ++;
        }
    }

    int ans = 0, cnt = 0;
    for(int i = 0; i < n; i ++){
        if(a[i] == 0){
            cnt ++;
        }
        else{
            cnt = 0;
        }
        ans = max(ans, cnt);
    }
    ans = max(ans, cnt);
    // cout << ans << endl;

    if(t1 + ans > t2 - ans){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    


}