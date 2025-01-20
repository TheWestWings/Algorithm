#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

const int N = 1000;

int maze[N][N];
int dx[] = {0 ,1, 0, -1};   
int dy[] = {1, 0, -1, 0};

int cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return abs(a.x) < abs(b.x);
}

int main(){
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> v;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            cin >> maze[i][j];
            if(maze[i][j] != 0) v.push_back({maze[i][j], {i, j}});
        }
    }

    sort(v.begin(), v.end(), cmp);

    // for(int i = 0; i < v.size(); i ++){
    //     cout << v[i].x << " " << v[i].y.x << " " << v[i].y.y << endl;
    // }

    // for(int i = 0; i < v.size(); i ++){
    //     for(int j = i + 1; j < v.size(); j ++){
    //         if(v[i].x == v[j].x){
    //             for(int k = 0; k < 4; k ++){
    //                 int x = v[i].y.x + dx[k];
    //                 int y = v[i].y.y + dy[k];
    //                 if(v[j].y.x == x && v[j].y.y == y){
    //                     // cout << x << " " << y << endl;
    //                     cout << "NO" << endl;
    //                     return 0;
    //                 }
    //             }
    //         }
    //     }
    // }

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            for(int k = 0; k < 4; k ++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(maze[i][j] < 0 && maze[x][y] < 0){
                    cout << "NO" << endl;
                    return 0;
                }
                else if(maze[i][j] > 0 && maze[x][y] > 0){
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    cout <<"YES" << endl;
}