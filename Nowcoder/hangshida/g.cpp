#include <bits/stdc++.h>

using namespace std;

int count(int n){
    int cnt = 0;
    while(n){
        cnt += n % 2;
        n /= 2;
    }
    // cout << cnt << endl;
    return cnt;
}

int main(){
    int n;
    cin >> n;

    if(n % 2 == 1){
        cout << (n + 1) / 2 << endl;
    }
    else{
        cout << (n + 2) / 2 << endl;
    }
    // int cnt = 0;
    // for(int i = 1; i < 100; i ++){
    //     if(count(i) % 2 == 1) cnt ++;
    //     cout << i << " " << cnt << endl;
    // }
}
