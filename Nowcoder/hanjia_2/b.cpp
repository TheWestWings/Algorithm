#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int a[N];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    sort(a, a + n, greater<int>());

    // for(int i = 0; i < n; i ++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    if(n % 2 == 0){
        for(int i = n / 2; i < n; i ++){
            if(a[i] != a[n / 2 - 1]){
                cout << a[n / 2 - 1] - 1 << endl;
                return 0;
            }
        }
        cout << a[n / 2] - 1 << endl;
    }
    else{
        for(int i = n / 2 + 1; i < n; i ++){
            if(a[i] != a[n / 2]){
                cout << a[n / 2] - 1 << endl;
                return 0;
            }
        }
        cout << a[n / 2] - 1 << endl;
    }
}