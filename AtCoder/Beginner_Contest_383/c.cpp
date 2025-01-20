#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

char maze[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main(){
    int n, m, d;
    cin >> n >> m >> d;
    // cout << n << m << d << endl;

    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        for(int j = 1; j <= m; j++){
            maze[i][j] = str[j - 1];
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << maze[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    queue<pair<pair<int, int>, int>> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(maze[i][j] == 'H'){
                q.push({{i, j}, 0});
            }
        }
    }
    while(!q.empty()){
        auto [p, dis] = q.front();
        q.pop();
        if(dis == d){
            break;
        }
        for(int i = 0; i < 4; i++){
            int x = p.first + dx[i], y = p.second + dy[i];
            if(x >= 1 && x <= n && y >= 1 && y <= m && (maze[x][y] == '.')){
                maze[x][y] = 'H';
                q.push({{x, y}, dis + 1});
            }
        }
    }



    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(maze[i][j] == 'H'){
                ans ++;
            }
        }
    }


    cout << ans << endl;
}