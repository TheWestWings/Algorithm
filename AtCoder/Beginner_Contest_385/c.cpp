#include <bits/stdc++.h>

using namespace std;

const int N = 3010;

int h[N];



int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++) cin >> h[i];

    int ans = 1;
    for(int i = 0; i < n; i ++){
        for(int j = 1; i + j < n; j ++){
            int t = 1;
            for(int k = i + j; k < n; k += j){
                if(h[i] == h[k]) t ++;
                else{
                    break;
                }
                // ans = max(ans, t);
            }
            ans = max(ans, t);
        }
    }
    cout << ans << endl;
}