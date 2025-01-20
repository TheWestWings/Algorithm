#include <bits/stdc++.h>

using namespace std;

int a[5];

int main(){
    string n;
    cin >> n;
    
    for(int i = 0; i < 6; i ++){
        a[n[i] - '0'] ++;
    }

    if(a[1] == 1 && a[2] == 2 && a[3] == 3){
        cout << "Yes" << endl;
    }
    else cout << "NO" << endl;
}