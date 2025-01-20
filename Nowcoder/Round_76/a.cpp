#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int t = n;

    int cnt = 0;
    while(n){
        for(int i = 1; i <= 7 && n; i ++){
            if(i == 6 || i == 7) cnt ++;
            n --;
        }
    }
    cout << t * 3 - cnt * 3 << endl;

}