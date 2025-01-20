#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

char a[N][N];

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = -0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < n - 2; i ++){
        for(int j = 0; j < n - 2; j ++){
            int cnt = 0;
            for(int x = i; x < i + 2; x ++){
                for(int y = j; y < j + 2; y ++){
                    if(a[x][y] == '*'){
                        cnt ++;
                    }
                }
            }
            if(cnt = 4){
                ans ++;
            }
        }
    }
cout << ans << endl;
    
}