#include <bits/stdc++.h>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;



    int dot1 = a.size(), dot2 = b.size();
    for(int i = 0; i < a.size(); i ++){
        if(a[i] == '.'){
            dot1 = i;
            break;
        }
    }

    for(int i = 0; i < b.size(); i ++){
        if(b[i] == '.'){
            dot2 = i;
            break;
        }
    }

    int n1 = a.size(), n2 = b.size();
    for(int i = n1; i < n2; i ++){
        a += '0';
    }
    for(int i = n2; i < n1; i ++){
        b += '0';
    }

    n1 = a.size();
    n2 = b.size();

    if(dot1 != dot2){
        cout << "NO" << endl;
        return 0;
    }

    for(int i = 0; i < dot1; i ++){
        if(a[i] != b[i]){
            cout << "NO" << endl;
            return 0;
        }
    }

    // cout << a << endl;
    // cout << b << endl;

    for(int i = dot1 + 1; i < n1; i ++){
        // cout << i << " " << a[i] << " " << b[i] << endl;
        if(a[i] != b[i] && i - dot1 <= 6){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;  
}