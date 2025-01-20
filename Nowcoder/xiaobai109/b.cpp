#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int main(){
    int n, k1, k2;
    cin >> n >> k1 >> k2;

    int mx = 0, mxi = 0;
    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        if(x > mx){
            mx = x;
            mxi = i;
        }
    }

    if(mxi == n - 1){
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;

}