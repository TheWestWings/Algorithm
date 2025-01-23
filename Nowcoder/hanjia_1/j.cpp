#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int a[N];

int main(){
    int n;
    cin >> n;

    map<int, int> mp;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        mp[a[i]] ++;
    }

    int ans = 0;
    for(int i = 0; i < n; i ++){
        for(int j = 2; j < a[i] / j; j ++){
            if(a[i] % j == 0){
                int t = a[i] - j;
                if((t ^ a[i]) == j){
                    ans += mp[t];
                }
                int x = a[i] / j;
                if(x == j) continue;
                t = a[i] - x;
                if((t ^ a[i]) == x){
                    ans += mp[t];
                }
            }
        }
    }
    cout << ans << endl;
}