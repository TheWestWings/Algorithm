#include <bits/stdc++.h>

using namespace std;

int a[10];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        a[x] ++;
    }

    int mx = 0, mn = 1e9;
    for(int i = 1; i <= 9; i ++){   
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    if(mx - mn > 1){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }


}