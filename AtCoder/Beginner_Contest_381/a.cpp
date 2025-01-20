#include <bits/stdc++.h>

using namespace std;

bool solve(){
    int n;
    cin >> n;

    string str;
    cin >> str;

    if(n % 2 != 1) return false;

    // cout << (n + 1) / 2 << endl;
    
    for(int i = 0; i < (n + 1) / 2 - 1; i ++){
        if(str[i] != '1'){
            
            return false;
        }
    }

    
    if(str[(n + 1) / 2 - 1] != '/') return false;
    
    for(int i = (n + 1) / 2 ; i < n; i ++){
        if(str[i] != '2'){
            
            return false;
        }
    }

    return true;

}

int main(){
    int t = 1;

    while(t --){
        if(solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
}