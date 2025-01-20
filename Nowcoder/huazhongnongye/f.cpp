#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int a[N];
// int st[N];

void solve(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }


    int ans = 0;
    map<int, int> st;
    for(int i = 0; i < n; i ++){
        if(st[a[i]] == 0){
            st[a[i]] = 1;
            // ans ++;
            continue;
        }
        else{
            st.clear();
            ans ++;
            st[a[i]] = 1;
        }
    }
    ans ++;
    cout << ans << " " << n << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}