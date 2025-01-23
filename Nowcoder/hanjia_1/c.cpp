#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int maze[N][N];
int n;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool ss[N][N];

vector<array<int, 4>> ans;

void dfs(int a, int b, int x, int y, vector<vector<int>>& dist){
    if(a == x && b == y){
        return;
    }

    for(int i = 0; i < 4; i ++){
        int c = a + dx[i], d = b + dy[i];
        if(c < 0 || c >= n || d < 0 || d >= n) continue;
        if(dist[c][d] == dist[a][b] - 1){
            // cout << a + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1 << endl;
            ans.push_back({c + 1, d + 1, a + 1, b + 1});
            dfs(c, d, x, y, dist);
            break;
        }
    }
}

void bfs(int x, int y){
    vector<vector<int>> dist(N, vector<int>(N, -1));
    dist[x][y] = 0;
    queue<pair<int, int>> q;
    q.push({x, y});

    while(q.size()){
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i ++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= n) continue;
            // if(a < n / 2 && b < n / 2 && maze[a][b] == 1) continue;
            if(ss[a][b]) continue;
            if(dist[a][b] != -1) continue;
            dist[a][b] = dist[t.first][t.second] + 1;
            q.push({a, b});
            if(maze[a][b] == 1){
                maze[a][b] = 0;
                maze[x][y] = 1;
                dfs(a, b, x, y, dist);
                return;
            }
        }
    }
}

void solve(){   
    cin >> n;

    for(int i = 0; i < n; i ++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j ++){
            maze[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < n / 2; i ++){
        for(int j = 0; j < n / 2; j ++){
            if(maze[i][j] == 0 && !ss[i][j]){
                bfs(i, j);
            }
            ss[i][j] = true;
        }
    }

    cout << ans.size() << endl;
    for(auto item : ans){
        cout << item[0] << " " << item[1] << " " << item[2] << " " << item[3] << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t --){
        ans.clear();
        memset(ss, false, sizeof ss);
        solve();
    }
}