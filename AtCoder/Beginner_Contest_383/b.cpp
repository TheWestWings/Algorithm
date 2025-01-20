#include <bits/stdc++.h>

using namespace std;

const int N = 20;

char maze[N][N], new_maze[N][N];

int main(){
    int n, m, d;
    cin >> n >> m >> d;



    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> maze[i][j];
        }
    }




    int mx2 = 0, mx_i2 = -1, mx_j2 = -1, ans = 0;;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            for(int i2 = 1; i2 <= n; i2 ++){
                for(int j2 = 1; j2 <= m; j2 ++){
                    if(i == i2 && j == j2){
                        continue;
                    }
                    memcpy(new_maze, maze, sizeof(maze));
                    if(new_maze[i][j] == '.' && new_maze[i2][j2] == '.'){
                        int cnt = 0;
                        for(int k = 1; k <= n; k ++){
                            for(int l = 1; l <= m; l ++){
                                if(abs(k - i) + abs(l - j) <= d && new_maze[k][l] == '.'){
                                    cnt ++;
                                    new_maze[k][l] = '#';
                                }
                                if(abs(k - i2) + abs(l - j2) <= d && new_maze[k][l] == '.'){
                                    cnt ++;
                                    new_maze[k][l] = '#';
                                }
                            }
                        }
                        ans = max(ans, cnt);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}