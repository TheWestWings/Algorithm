#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int cnt[N];
int pos[N];

int main(){
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i ++){
        cnt[i] = 1;
        pos[i] = i;
    }

    int ans = 0;
    while(q --){
        int op;
        cin >> op;
        if(op == 1){
            int a, b;
            cin >> a >> b;
            if(cnt[pos[a]] == 2) ans --;
            cnt[pos[a]] --;
            if(cnt[pos[a]] < 0) cnt[pos[a]] = 0;
            if(cnt[b] == 1) ans ++;
            cnt[b] ++;
            pos[a] = b;
        }
        else{
            cout << ans << endl;
        }
    }

}