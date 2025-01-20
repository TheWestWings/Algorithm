#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int a[N];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i ++){
        if(a[i] == 1){
            ans++;
        }
    }

    cout << ans << endl;
}