#include <bits/stdc++.h>

using namespace std;

int ans = 0, mx = 0;
int cnt = 0;
int n;

void dfs(int u, int num, vector<int> &lst){
    if(u == n){
        int a = num;
        int t = 0;
        while(a){
            t ++;
            a /= 10;
        }
        if(t != n){
            return;
        }
        // cout << num ;
        ans = 1;
        int x = 1;
        a = num;
        
        int ct = 0;
        while(num){
            int t = num % 1000;
            ans *= t;
            num /= 1000;
        }
        // cout << " " << x << endl;
        if(ct){
            ans *= x;
        }
        if(ans > mx){
            mx = ans;
            // cout << a << endl;
        }
        // mx = max(mx, ans);
    }

    for(int i = 0; i < lst.size(); i ++){
        if(lst[i] == -1){
            continue;
        }
        int t = lst[i];
        lst[i] = -1;
        dfs(u + 1, num * 10 + t, lst);
        lst[i] = t;
    }
}




int main(){
    int x;
    cin >> x;
    if(x == 0){
        cout << 0 << endl;
        return 0;
    }

    vector<int> num;
    while(x){
        num.push_back(x % 10);
        x /= 10;
    }
    n = num.size();

    cnt = n / 3;
    if(n % 3){
        cnt ++;
    }


    dfs(0, 0, num);
    cout << mx << endl;
}