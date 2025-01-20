#include <bits/stdc++.h>

using namespace std;

int main(){
    string str1, str2;
    cin >> str1 >> str2;

    int n1 = str1.size(), n2 = str2.size();

    int idx1 = n1 , idx2 = n2;

    for(int i = 0; i < n1; i ++){
        if(str1[i] == '.') idx1 = i;
    }

    for(int j = 0; j < n2; j ++){
        if(str2[j] == '.') idx2 = j;
    }

    if(idx1 != idx2) {
        cout << "NO" << endl;
        return 0;
    }

    for(int i = 0; i < idx1; i ++){
        if(str1[i] != str2[i]){
            cout << "NO" << endl;
            return 0;
        }
    }

    str1.append("0000000000");

    for(int i = idx1 + 1; i < idx1 + 7; i ++){
        if(str1[i] != str2[i]){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}