#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v;
    for(int i = 1; i <= n; i ++){
        v.push_back(i);
    }

    int cnt = 0;
    do{

        // cout << endl;
        int ans = 0;
        vector<int> a(n);
        for(int i = 0; i < n; i ++){
            int mn = 0x3f3f3f3f;
            for(int j = i; j < n; j ++){
                mn = min(mn, v[j]);
                // cout << mn << " ";
                ans += mn;
                // a[j] ++; 
                // for(int k = i; k <= j; k ++){
                //     a[k] ++;
                // }
            }
            // ans += mn;
        }
        // cout << ans << endl;

        int t = 0;
        for(int i = 1; i <= n; i ++){
            t += i * (n - i + 1);
        }
        if(ans == t){
            for(auto x : v){
                cout << x << " ";
            }
            cout << endl;
            cnt ++;
        }
        

        // for(auto x : a){
            // cout << x << " ";
        // }
        // cout << endl;
    }while(next_permutation(v.begin(), v.end()));
    cout << cnt << endl;
}