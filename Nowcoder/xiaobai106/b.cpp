#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int a[N][N];

int main(){
    int n;
    cin >> n;

    int cnt = 1;

    for(int i = 1; i <= n; i ++){
        a[1][i] = cnt ++;
    }
    for(int i = 2; i <= n; i ++){
        for(int j = 1; j < i; j ++){
            a[i][j] = a[j][i - 1];
        }
        for(int j = i; j <= n; j ++){
            a[i][j] = cnt ++;
        }
    }

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

}