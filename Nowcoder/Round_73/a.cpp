#include <bits/stdc++.h>

using namespace std;


int main(){
    int l, r, x;
    cin >> l >> r >> x;

    for(int i = l; i <= r; i++){
        if(i % x == 0){
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}