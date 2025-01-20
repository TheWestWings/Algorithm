#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

// int a[N], b[N];

int main(){
    int n;
    cin >> n;

    string str;
    cin >> str;

    vector<char> a(n), b(n);

    for(int i = 0; i < n; i ++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            a.push_back( str[i]);
        }
        if(str[i] >= 'A' && str[i] <= 'Z'){
            b.push_back( str[i]);
        }
    }

    for(int i = 0; i < a.size(); i ++){
        cout << a[i];
    }
    for(int i = 0; i < n; i ++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            continue;
        }
        if(str[i] >= 'a' && str[i] <= 'z'){
            continue;
        }
        cout << str[i];
    }

    for(int i = 0; i < b.size(); i ++){
        cout << b[i];
    }


    
}