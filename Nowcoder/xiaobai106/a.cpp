#include <bits/stdc++.h>

using namespace std;

int qmi(int a, int b, int mod){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;



    if(a % 2 == 0 && d % 2 == 0 && c % 2 == 0){
        cout << "NO" << endl;
        return 0;
    }
    else if(b == 0 && c % 2 == 0 && d % 2 == 0){
        cout << "NO" << endl;
        return 0;
    }
    else if(c == 0 && d % 2 == 0){
        cout << "NO" << endl;
        return 0;
    }
    else if(a % 2 != 0 && d % 2 != 0 && c % 2 != 0){
        cout << "NO" << endl;
        return 0;
    }
    else if(a % 2 != 0 && c % 2 == 0 && d % 2 == 0){
        cout << "NO" << endl;
        return 0;
    }

    else{
        cout << "YES" << endl;
        return 0;
    }
}