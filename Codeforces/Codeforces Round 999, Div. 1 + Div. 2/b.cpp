#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int a[N];

void solve(){
    int n;
    cin >> n;

    vector<int> di;
    map<int, int> mp;   
    for(int i = 0; i < n; i ++){
        int x;
        cin >> x; 
        mp[x] ++;
    }

    int yao = 0;
    for(auto it : mp){
        if(it.second >= 2 && it.first > yao){
            yao = it.first;
        }
    }

    for(auto it : mp){
        if(it.first == yao){
            it.second -= 2;
        } 
        while(it.second --){
            di.push_back(it.first);
        }
    }

    sort(di.begin(), di.end());

    
    int lar = di[di.size() - 1] - di[0];
    int sam = 0x3f3f3f3f;
    int ans1 = -1, ans2 = -1;
    for(int i = 0; i < di.size() - 1; i ++){
        if(di[i + 1] - di[i] < sam){
            sam = di[i + 1] - di[i];
            ans1 = di[i];
            ans2 = di[i + 1];
        }
    }

    if(yao == 0){
        cout << -1 << endl;
        return;
    }

    if(yao * 2 > sam){
        cout << yao << " " << yao << " " << ans1 << " " << ans2 << endl;
        return;
    }

    cout << -1 << endl;
    
}

int main(){
    int t;
    cin >> t;

    while(t --) solve();
}