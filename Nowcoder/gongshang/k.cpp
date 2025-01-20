#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int a[N];

int main(){
    int n, k;
    cin >> n >> k;

    map<int, int> mp;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        mp[a[i]] ++;
    }

    int ans = -1;
    for(auto t : mp){
        if(t.second == k){
            ans = t.first;
        }
    }
    cout << ans << endl;


}