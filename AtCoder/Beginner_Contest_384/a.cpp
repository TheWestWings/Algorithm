#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<char> v;
    int n;
    char a, b;
    string str;
    cin >> n;
    cin >> a >> b;
    cin >> str;

    for(int i = 0; i < n; i ++){
        v.push_back(str[i]);
    }

    for(int i = 0; i < n; i ++){
        if(v[i] != a){
            v[i] = b;
        }
    }

    for(int i = 0; i < n; i ++){
        cout << v[i];
    }
}