#include <bits/stdc++.h>

using namespace std;

const int N = 13;

char maze[N][N];

int h, w, k;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dfs(int x, int y, int d, set<pair<int, int>> &path){
    if(d == k){
        return 1;
    }

    int ans = 0;
    for(int i = 0; i < 4; i ++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a >= h || b < 0 || b >= w || path.find({a, b}) != path.end() || maze[a][b] == '#') continue;
        path.insert({a, b});
        ans += dfs(a, b, d + 1, path);
        path.erase({a, b});
    }

    return ans;
}

int main(){
    // int h, w;
    cin >> h >> w >> k;

    for(int i = 0; i < h; i ++){
        for(int j = 0; j < w; j ++){
            cin >> maze[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0; i < h; i ++){
        for(int j = 0; j < w; j ++){
            if(maze[i][j] == '#') continue;
            set<pair<int, int>> path;
            path.insert({i, j});
            cnt += dfs(i, j, 0, path);
        }
    }

    cout << cnt << endl;
}