#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    set<int> s;
    for(int i = 1; i <= n; i++){
        s.insert(i);
    }

    map <int, int> ans;
    int cnt = 1;
    while(q --){
        int op;
        cin >> op;
        if(op == 1){
            int l, r;
            cin >> l >> r;

            auto it = s.lower_bound(l);
            while(it != s.end() && *it <= r){
                // cout << *it << endl;
                ans[*it] = cnt ++;
                it = s.erase(it);
            }
        }
        else{
            int x;
            cin >> x;
            cout << ans[x] << endl;
        }
    }
}