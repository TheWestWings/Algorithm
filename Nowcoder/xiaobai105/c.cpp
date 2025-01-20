#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

char maze[2][N];

int main(){
    int n;
    cin >> n;

    maze[0][0] = maze[1][0] = 'x';
    for(int i = 1; i <= n; i ++){
        cin >> maze[0][i];
    }
    for(int i = 1; i <= n; i ++){
        cin >> maze[1][i];
    }
    maze[0][n + 1] = maze[1][n + 1] = 'x';

    int ans = 0;
    for(int i = 1; i <= n; i ++){
        if(maze[0][i] == '.'){
            if(maze[1][i] == 'x' && maze[0][i + 1] == 'x' && maze[0][i - 1] == 'x') ans ++;
            else if(maze[0][i + 1] == '.' && maze[1][i] == '.' && maze[1][i + 1] == 'x') ans ++;
            else if(maze[0][i + 1] == '.' && maze[0][i - 1] == '.' && maze[1][i] == 'x') ans ++;
            else if(maze[0][i - 1] == '.' && maze[1][i] == '.' && maze[1][i - 1] == 'x') ans ++;
        }   
    }

    for(int i = 1; i <= n; i ++){
        if(maze[1][i] == '.'){
            if(maze[0][i] == 'x' && maze[1][i + 1] == 'x' && maze[1][i - 1] == 'x') ans ++;
            else if(maze[1][i + 1] == '.' && maze[0][i] == '.' && maze[0][i + 1] == 'x') ans ++;
            else if(maze[1][i + 1] == '.' && maze[1][i - 1] == '.' && maze[0][i] == 'x') ans ++;
            else if(maze[1][i - 1] == '.' && maze[0][i] == '.' && maze[0][i - 1] == 'x') ans ++;
        }
    }

    cout << ans << endl;

}