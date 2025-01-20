#include <bits/stdc++.h>

using namespace std;

int main(){
    int l, r;
    cin >> l >> r;

    int ans = -1, ans_n = -1;
    for(int i = l; i <= r; i ++){
        int cnt = 0;
        for(int j = 1; j < i; j ++){
            if(i % j == 0){
                cnt ++;
            }
        }
        if(cnt >= ans_n){
            ans_n = cnt;
            ans = i;
        }
    }
    cout << ans << " " << ans_n << endl;
}