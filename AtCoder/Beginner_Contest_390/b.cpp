#include <bits/stdc++.h>

using namespace std;

const int N = 100;

char az[N][N];
char bz[N][N];

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> az[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cin >> bz[i][j];
        }
    }

    int ans_a = -1, ans_b = -1;
    for(int a = 0; a < n - m + 1; a++){
        for(int b = 0; b < n - m + 1; b++){
            bool flag = true;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < m; j++){
                    if(az[a + i][b + j] != bz[i][j]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                ans_a = a;
                ans_b = b;
                break;
            }
        }
    }
    cout << (ans_a + 1) << " " << (ans_b + 1) << endl;
}