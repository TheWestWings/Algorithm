#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int a[N];

bool solve(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    for(int i = 0; i < n - 1; i ++){
        // for(int j = i + 1; j < n; j ++){
        int j = (i + 1);
        if(abs(a[i] - a[j]) != 5 && abs(a[i] - a[j]) != 7) return false;
        // }
    }
    return true;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        if(solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}