#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
typedef pair<int, int> PII;

PII a[N];
int p[N];

int find(int x){
    if(p[x] != x){
        p[x] = find(p[x]);
    }
    return p[x];
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> a[i].first;
    }
    for(int i = 0; i < n; i ++){
        cin >> a[i].second;
    }

    sort(a, a + n);

    // for(int i = 0; i < n; i ++){
    //     cout << a[i].first << " " << a[i].second << endl;
    // }

    int ans = 0, j = 0;
    int t = n - 1;
    for(int i = 0; i < n; i ++){
        // cout << ans << " " << t << endl;
        // ans += a[i].first;
        if(i != 0){
            ans += a[i].first;
            a[i].second --;
            t --;
        } 
        ans += a[i].first * min(a[i].second, t);
        t -= a[i].second;
        if(t <= 0){
            break;
        }
    }
    cout << ans << endl;
}