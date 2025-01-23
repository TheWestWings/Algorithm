#include <bits/stdc++.h>

using namespace std;

const int N = 110;

char maze[N][N];

int main(){
    int n, m;
    cin >> n >> m;

    int x, y;
    cin >> x >> y;

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> maze[i][j];
        }
    }

    string str;
    cin >> str;

    int cnt = 0;
    for(int i = 0; i < str.size(); i ++){
        if(str[i] == 'U'){
            int a = x - 1, b = y;
            if(a <= 0 || a > n || b <= 0 || b > m || maze[a][b] == '#') continue;
            x = a, y = b;
            if(maze[x][y] == '@'){
                maze[x][y] = '.';
                cnt ++;
            }
        }
        else if(str[i] == 'D'){
            int a = x + 1, b = y;
            if(a <= 0 || a > n || b <= 0 || b > m || maze[a][b] == '#') continue;
            x = a, y = b;
            if(maze[x][y] == '@'){
                maze[x][y] = '.';
                cnt ++;
            }
        }
        else if(str[i] == 'L'){
            int a = x, b = y - 1;
            if(a <= 0 || a > n || b <= 0 || b > m || maze[a][b] == '#') continue;
            x = a, y = b;
            if(maze[x][y] == '@'){
                maze[x][y] = '.';
                cnt ++;
            }
        }
        else if(str[i] == 'R'){
            int a = x, b = y + 1;
            if(a <= 0 || a > n || b <= 0 || b > m || maze[a][b] == '#') continue;
            x = a, y = b;
            if(maze[x][y] == '@'){
                maze[x][y] = '.';
                cnt ++;
            }
        }
        // cout << x << " " << y << " " << endl;
    }
    cout << x << " " << y << " " << cnt << endl;
} 