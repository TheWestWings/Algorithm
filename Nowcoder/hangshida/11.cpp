#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;


    if(m > n){
        if(n + n > m + (m - n)){
            cout << n + n << endl;
            for(int i = 1; i <= n; i ++){
                cout << i << " " << 1 << endl;
            }
            for(int i = 1; i < m; i ++){
                cout << i << " " << n << endl;
            }
        }
    }
}