#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    string str;
    cin >> str;

    int ei = -1, zi = -1;
    for(int i = 0; i < n; i ++){
        if(str[i] == 'e' && ei == -1){
            ei = i;
        }
        if(str[i] == 'z'){
            zi = i;
        }
    }

    if(ei == -1 || zi == -1){
        cout << "hard" << endl;
        return 0;
    }
    else if(zi > ei){
        cout << "easy" << endl;
    }
    else{
        cout << "hard" << endl;
    }
}