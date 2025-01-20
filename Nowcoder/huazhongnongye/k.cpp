#include <bits/stdc++.h>

using namespace std;

const int N = 110 * 110;

int x[N], y[N];

int main(){
    int n, m, k;

    cin >> n >> m >> k;

    for(int i = 1; i <= k; i ++){
        cin >> x[i] >> y[i];
    }

    int ans = 0, ansx, ansy;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            int t = 0x3f3f3f3f;
            bool flag = true;
            for(int l = 1; l <= k; l ++){
                if(x[l] == i && y[l] == j){
                    flag = false;
                    break;
                }
                if(abs(x[l] - i) + abs(y[l] - j) < t){
                    t = abs(x[l] - i) + abs(y[l] - j);
                }
            }
            if(t > ans && flag){
                ans = t;
                ansx = i;
                ansy = j;
            }
        }
    }
    cout << ans << endl;
    cout << ansx << " " << ansy << endl;
}