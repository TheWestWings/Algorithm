#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10;

int a[N];

signed main(){
    int n;
    cin >> n;

    int s = 0;
    map<int, int> mp;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        s += a[i];
        mp[a[i]] ++;
    }

    int ans = 0;
    // vector<int> v;
    // for(int i = 1; i <= n; i ++){
    //     while(mp[i] > 1){
    //         v.push_back(i);
    //         mp[i] --;
    //     }
    // }

    // sort(v.begin(), v.end());
    // for(int i = 0; i < n; i ++){
    //     if(mp[i] == 0){
    //         ans += v.back() - i;
    //         v.pop_back();
    //     }
    // }

    sort(a, a + n);
    for(int i = 0; i < n; i ++){
        if(a[i] != i + 1){
            ans += abs(a[i] - i - 1);
        }
    }

    if(s == (1 + n) * n / 2){
        cout << ans / 2 << endl;
    }
    else{
        cout << -1 << endl;
    }
}