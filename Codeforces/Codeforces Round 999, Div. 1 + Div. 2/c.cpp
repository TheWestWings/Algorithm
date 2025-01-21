#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

void solve(){
    int n, m;
    cin >> n >> m;

    multiset<int> mp;
    int mn = 0x3f3f3f3f;
    int s1 = 0, s2 = 0;
    priority_queue<int, vector<int>, greater<int>> a;
    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        mp.insert(x);
        s1 += x;
        a.push(x);
    }
    mn = a.top();

    priority_queue<int, vector<int>, greater<int>> b;
    for(int i = 0; i < m; i ++){
        int x;
        cin >> x;
        s2 += x;
        b.push(x);
    }

    if(s1 != s2){
        cout << "NO" << endl;
        return;
    }

    while(b.size()){
        int x = b.top();
        b.pop();
        if(mp.find(x) != mp.end()){
            mp.erase(mp.find(x));
            // for(auto it : mp){
            //     if(it.second != 0){
            //         mn = min(mn, it.first);
            //         break;
            //     }
            // }
            mn = (*mp.begin());
        }
        else{
            if(x % 2 == 0){
                b.push(x / 2);
                b.push(x / 2);
            }
            else{
                b.push(x / 2);
                b.push(x / 2 + 1);
            }
            if(x / 2 < mn){
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;

}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}

