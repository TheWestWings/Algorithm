#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    string str;
    cin >> str;

    if(str[n - 1] != '1'){
        cout << -1 << endl;
        return 0;
    }

    int j = 0;
    for(int i = 0; i < n; i ++){
        if(str[i] == '1'){
            int t = i + 1;
            for(j; j <= i; j ++){
                cout << t << " ";
                t --;
            }
        }
    }

}