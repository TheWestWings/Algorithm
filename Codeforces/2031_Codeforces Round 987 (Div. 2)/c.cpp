#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

void solve(){
    int n;
    cin >> n;

    

    if(n % 2 != 0 && n < 27){
        cout << -1 << endl;
        return;
    }
    else if(n % 2 == 0 && n < 27){
        int t = 1;
        for(int i = 1; i <= n; i += 2){
            cout << t << " " << t << " ";
            t += 1; 
        }
        cout << endl;
        return;
    }
    else if(n % 2 == 0){
        int t = 1;
        for(int i = 1; i <= n; i += 2){
            cout << t << " " << t << " ";
            t += 1; 
        }
        cout << endl;
        return;
    }
    else{
        vector<int> res(n + 1, -1);
        res[1] = N;
        res[17] = N;
        res[23] = N + 2;
        res[27] = N + 2;
        res[26] = N;
        res[14] = N + 1;
        res[18] = N + 1;

        int t = 1;
        int cnt = 0;
        for(int i = 1; i <= n; i ++){
            if(res[i] == -1){
                res[i] = t;
                cnt ++;
                if(cnt == 2){
                    t ++;
                    cnt = 0;
                }
            }
            cout << res[i] << " ";
        }
        cout << endl;
        return ;
    }
}

int main(){
    int t;
    cin >> t;
    while(t --){
        solve();;
    }
}