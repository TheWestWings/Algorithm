#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

void solve(){
    int a, b;
    cin >> a >> b;

    cout << lcm(a, b) << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}