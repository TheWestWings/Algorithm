#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int main(){
    int n, k;
    cin >> n >> k;

    if(k > n){
        cout << "NO" << endl;
        return 0;
    }

    int t = n - k + 1;
    for(int i = 0; i < n; i ++){
        cout << i % t << " ";
    }
}