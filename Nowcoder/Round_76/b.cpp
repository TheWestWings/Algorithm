#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int cnt[N];

int main(){
    int n;
    cin >> n;

    string str;
    cin >> str;

    int mx = 0;
    char mx_id;
    for(int i = 0; i < n; i ++){
        cnt[str[i] - 'a'] ++;
        if(cnt[str[i] - 'a'] > mx){
            mx = cnt[str[i] - 'a'];
            mx_id = str[i];
        }

    }

    cout << mx_id << endl;

}