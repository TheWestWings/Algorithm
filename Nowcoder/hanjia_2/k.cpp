#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int maze[N][N];

bool st[N][N];

queue<pair<int, int>> q;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;

void dfs(int x, int y){
    if(st[x][y] || maze[x][y] != 1) return;
    st[x][y] = true;
    for(int i = 0; i < 4; i ++){
        int a = x + dx[i], b = y + dy[i];
        if(a >= 0 && a < n && b >= 0 && b < m && maze[a][b] == 1 && !st[a][b]){
            q.push({a, b});
            dfs(a, b);
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            scanf("%1d", &maze[i][j]);
        }
    }


    int ans = 0x3f3f3f3f;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(!st[i][j] && maze[i][j] == 1){
                q.push({i, j});
                dfs(i, j);
                int cnt = 0;
                vector<vector<int>> dist(n, vector<int>(m, 0));
                // cout << q.size() << endl;
                while(q.size()){
                    auto p = q.front();
                    // cout << p.first << " " << p.second << endl;
                    q.pop();
                    int x = p.first, y = p.second;

                    for(int i = 0; i < 4; i ++){
                        int a = x + dx[i], b = y + dy[i];
                        // cout << a << " " << b << endl;
                        // if(a >= 0 && a < n && b >= 0 && b < m)cout << maze[a][b] << " " << dist[a][b] << endl;
                        if(a >= 0 && a < n && b >= 0 && b < m && maze[a][b] == 0 && dist[a][b] == 0){
                            cnt ++;
                            dist[a][b] = 1;
                        }
                    }
                }   
                ans = min(ans, cnt);         
            }
        }
    }
    cout << ans << endl;
}