#include <bits/stdc++.h>

using namespace std;

int a[5];

bool solve(){
    int n = 4;
    for(int i = 0; i < n; i ++) cin >> a[i];

    for(int i = 0; i < n - 1; i ++){
        if(a[i] != a[i + 1]){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin >> t;

    while(t --)
    if(!solve()){
        cout << "YES" << endl;}
    else{
        cout << "NO" << endl;}

}