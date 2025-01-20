#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int a[N];

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int jia = 0, jian = 0, gong = 0;
    for(int i = 1; i <= n; i ++){
        if(a[i] != i){
            jia ++;
        }
        if(a[i] != n - i + 1){
            jian ++;
        }
        if(a[i] != i && a[i] != n - i + 1){
            gong ++;
        }
    }
    jia -= gong;
    jian -= gong;
    if(jia > jian){
        jia -= jian;
        jian = 0;
    }
    else{
        jian -= jia;
        jia = 0;
    }
    if(jia > gong){
        cout << "jian" << endl;
    }
    else if(jian >= gong){
        cout << "jia" << endl;
    }
    else{
        cout << "orz" << endl;
    }
}