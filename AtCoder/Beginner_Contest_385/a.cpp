#include <bits/stdc++.h>

using namespace std;

const int N = 5;

int a[N];

int main(){
    cin >> a[0] >> a[1] >> a[2];

    if(a[0] + a[1] == a[2] || a[0] + a[2] == a[1] || a[1] + a[2] == a[0] || (a[0] == a[1] && a[1] == a[2])){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}