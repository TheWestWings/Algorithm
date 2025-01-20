#include <bits/stdc++.h>

using namespace std;

void solve(){
    string str;
    cin >> str;

    int n = str.size();
    vector<char> v;
    for(int i = 0; i < n; i ++){
        v.push_back(str[i]);
    }

    for(int i = n - 1; i >= 0; i --){
        if(v[i] == 'q'){
            cout << "p";
        }
        else if(v[i] == 'p'){
            cout << "q";
        }
        else cout << v[i];
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}