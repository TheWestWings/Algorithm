#include <bits/stdc++.h>

using namespace std;    

const int N = 2e5 + 10, M = 1e9 + 7;

int a[N], b[N];
map<int, int> mp;
// bool st[M];

int main(){
    int n;
    cin >> n;

    memset(b, -1 ,sizeof b);
    // memset(mp, -1, sizeof mp);

    for(int i = 0; i < n; i ++){
        cin >> a[i];
        mp[a[i]] = -1;
        
    }

    for(int i = 0; i < n; i ++){
        if(mp.count(a[i])){
            b[i] = mp[a[i]];
        }
        // b[i] = mp[a[i]];
        mp[a[i]] = i;
    }

    for(int i = 0; i < n; i ++){
        
        if(b[i] != -1) cout << b[i] + 1 << " ";
        else cout << -1 << " ";
    }
}