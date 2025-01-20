#include <bits/stdc++.h>

using namespace std;

int a[4];
int b[10];

int main() {

    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        cin >> a[i];
        b[a[i]] ++;
        if(b[a[i]] >= 2){
            b[a[i]] -= 2;
            cnt ++;
        }
    }
    cout << cnt << endl;

    
    
}