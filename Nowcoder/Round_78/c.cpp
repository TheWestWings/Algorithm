#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 10;

int g[N][N];
bool st[N];

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            scanf("%1d", &g[i][j]);
        }
    }

    for(int i = 0 ; i < n; i ++){
        // cout << i << endl;
        int cnt = 0;
        int t = 0;
        for(int j = 0; j < m; j ++){
            if(st[j]) continue;
            cnt ++;
            if(g[i][j] == 0){
                t ++;
            }
        }
        if(cnt - t > t){  //1¶à
            for(int j = 0; j < m; j ++){
                if(st[j]) continue;
                if(g[i][j] == 0){
                    // cout << j << endl;
                    st[j] = true;
                }
            }
        }
        else{   //0¶à   
            for(int j = 0; j < m; j ++){
                if(st[j]) continue;
                if(g[i][j] == 1){
                    st[j] = true;
                }
            }
        }
    }

    int ans = 0;
    for(int j = 0; j < m; j ++){
        if(!st[j]) ans ++;
    }
    cout << ans << endl;
}