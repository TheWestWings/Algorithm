#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    while(true){
        if(n >= a){
            n -= a;
            ans ++;
        }
        else if(n >= b){
            n -= b;
            ans ++;
        }
        else if(n >= c){
            n -= c;
            ans ++;
        }
        else{
            break;
        }
    }
    cout << ans << endl;
}