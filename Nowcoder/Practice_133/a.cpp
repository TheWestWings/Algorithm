#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N];

void solve(){
    int len, m;
    cin >> len >> m;

    int cnt = 0;
    while(m){
        m /= 2;
        cnt ++;
        
    }
    if(len < (1 << cnt)){
        cnt --;
    }
    cout << cnt << endl;
    
}

void init(){
    int s = 0;
    a[0] = 1;
    s = 1;
    for(int i = 1; i < N - 10; i ++){
        a[i] += s + 1;
        s += a[i];
    }
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}