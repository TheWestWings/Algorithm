#include <bits/stdc++.h>

using namespace std;
typedef pair<double, double> PII;


void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    PII x1 = {a, c}, x2 = {b, d};

    if(b - a >= d - c){
        cout << x1.first << " " << x1.second << endl;
        cout << x1.first + 1 << " " << x1.second << endl;
        cout << x2.first << " " << x1.second + 1 << endl;
    }
    else{
        cout << x1.first << " " << x1.second << endl;
        cout << x1.first + 1 << " " << x2.second << endl;
        cout << x1.first << " " << x1.second + 1<< endl;
    }    
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}