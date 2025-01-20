#include <bits/stdc++.h>

using namespace std;

void solve(){
    string str;
    cin >> str;

    vector<int> s;
    for(int i = 0; i < str.size(); i ++){
        s.push_back(str[i] - '0');
    }

    // for(int i = 0; i < s.size(); i ++){
    //     cout << s[i];
    // }
    // cout << endl;

    int n = str.size();
    for(int i = 0; i < n; i ++){
        int j = i;
        while(j > 0 && s[j] > 0 && s[j] - 1 > s[j - 1]){
            s[j] --;
            swap(s[j], s[j - 1]);
            j --;
        }
    }
    for(int i = 0; i < n; i ++){
        cout << s[i];
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --) solve();
}