#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin >> str;

    int n = str.size();

    for(int i = 0; i < n; i ++){
        if(i + 1 < n && str[i] == str[i + 1] && str[i] != '?'){
            cout << "-1" << endl;
            return 0;
        }
        if(str[i] == '?'){
            int j;
            for(j = i + 1; j < n; j ++){
                if(str[j] != '?'){
                    break;
                }
            }
            int flag = 0;
            while(i < j){
                if(flag == 0){
                    str[i] = str[i - 1] + 1;
                }
            }
        }

    }
}