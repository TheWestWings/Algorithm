#include <bits/stdc++.h>

using namespace std;

const int N = 40;


char c[N][N];
int a[N][N], s[N][N];

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> c[i] + 1;
    }

    // for(int i = 1; i <= n; i ++){
    //     for(int j = 1; j <= m; j++){
    //         // a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    //         cout << c[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(c[i][j] == '.'){
                a[i][j] = 0;
            }
            else{
                a[i][j] = 1;
            }
        }
    }

    // for(int i = 1; i <= n; i ++){
    //     for(int j = 1; j <= m; j++){
    //         // a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j++){
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }


    // for(int i = 1; i <= n; i ++){
    //     for(int j = 1; j <= m; j++){
    //         cout << s[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    int a_x1, a_y1, a_x2, a_y2;
    int mx = 0;
    for(int x1 = 1; x1 <= n; x1++){
        for(int y1 = 1; y1 <= m; y1++){
            for(int x2 = x1; x2 <= n; x2++){
                for(int y2 = y1; y2 <= m; y2++){
                    int sum = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
                    if(sum == 0){
                        if((x2 - x1 + 1) * (y2 - y1 + 1) > mx){
                            mx = (x2 - x1 + 1) * (y2 - y1 + 1);
                            a_x1 = x1;
                            a_y1 = y1;
                            a_x2 = x2;
                            a_y2 = y2;
                        }
                    }
                }
            }
        }
    }

    // cout << mx << endl;

    cout << a_x1 << " " << a_y1 << " " << a_x2 << " " << a_y2 << endl;
}