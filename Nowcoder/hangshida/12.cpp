#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin >> str;

    int n = str.size();

    vector<char> a;
    for(int i = 0; i < n; i++){
        a.push_back(str[i]);
    }

    for(int i = 0; i < n - 1; i ++){
        if(a[i] == 'G' && a[i + 1] == 'G'){
            a.erase(a.begin() + i);
            a.erase(a.begin() + i);
            i --;
            i --;
            n -= 2;
        }
        if(a[i] == 'B' && a[i + 1] == 'B'){
            a.erase(a.begin() + i);
            a.erase(a.begin() + i);
            i --;
            i --;
            n -= 2;
        }
    }

    // for(auto x : a){
    //     cout << x;
    // }

    for(int i = 0; i < n; i ++){
        if(a[i] == 'C' && i - 1 >= 0){
            a.erase(a.begin() + i - 1);
            a.erase(a.begin() + i - 1);
            // i --;
            // i --;
            i = 0;
            n --;
            n --;
        }
        else if(a[i] == 'C' && i + 1 < n){
            a.erase(a.begin() + i);
            a.erase(a.begin() + i);
            i = 0;
            n --;
            n --;
        }
    }


    cout << n << endl;
}