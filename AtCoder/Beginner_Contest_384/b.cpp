#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, mark;
    cin >> n >> mark;

    for(int i = 0; i < n; i ++){
        int op;
        cin >> op;
        if(op == 1){
            int x;
            cin >> x;
            if(mark >= 1600 && mark <= 2799){
                mark += x;
            }
        }
        else{
            int x;
            cin >> x;
            if(mark >= 1200 && mark <= 2399){
                mark += x;
            }
        }
    }
    cout << mark << endl;
}