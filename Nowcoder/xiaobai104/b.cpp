#include <bits/stdc++.h>

using namespace std;

const int N = 10;

double a[N];

double qmi(double a, int b){
    double res = 1;
    while(b){
        if(b & 1){
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

int main(){
    for(int i = 0; i < 5; i ++){
        cin >> a[i];
    }

    double x = a[0] + a[1] + a[2];
    double y = a[3] + a[4];
    cout << fixed << setprecision(10) << 1 - qmi(x, 10) - qmi(x, 9) * y * 10 << endl;
}