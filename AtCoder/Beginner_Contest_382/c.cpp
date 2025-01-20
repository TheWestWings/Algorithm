#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
typedef pair<int, int> pii;

int a[N];
pii b[N];

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    for(int j = 0; j < m; j ++){
        // cin >> b[j];
        int x;
        cin >> x;
        b[j] = {x, j + 1};
    }

    sort(b, b + m, greater<pii>());

    int i = 0;
    vector<int> ans(m ,-1);
    for(int j = 0; j < m && i < n; j ++){
        if(a[i] <= b[j].first){
            ans[b[j].second - 1] = i + 1;
        }
        else{
            i ++;
            j --;
        }
    }
    for(int i = 0; i < m; i ++){
        cout << ans[i] << endl;
    }

}

int main(){
    int t;
    // cin >> t;
    t = 1;

    while(t --){
        solve();
    }
}