#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;

    cin >> str;

    int cnt = 0, ans = 0;
    for(int i = 0; i < str.size(); i ++){
        if(str[i] == '|'){
            // ans ++;
            cnt ++;
        }
        else{
            ans ++;
        }
        
    }
}