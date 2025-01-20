#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a, b, c;
    cin >> n >> a >> b ;

    int cnt = 0;
    for(int i = 0; i < n / a; i ++){
        int j = (n - i * a) / b;
        cnt = max(cnt, i * a + j * b);
    }
    cout << cnt << endl;
}