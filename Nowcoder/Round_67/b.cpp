#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    while(n--){
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long a_max = floor((c * b)/ d);
        if(a_max * 1.0 / b  == c * 1.0 / d) a_max --;
        cout << a_max << endl;
        cout << a - a_max << endl;
    }
}

int main(){
    solve();
    // cout << floor(1.9);
    return 0;
}