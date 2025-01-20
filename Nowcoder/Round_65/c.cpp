#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
typedef long long LL;

LL a[N];

void solve(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    sort(a, a + n);

    LL ans1 = 0, ans2 = 0;

    for(int i = 0; i < n; i ++){
        if(i % 2 == 0){
            ans1 += a[i];
        }
        else{
            ans2 += a[i];
        }
    }
    if(ans1 - a[0] + a[n - 1] > ans2 - a[n - 1] + a[0]){
        cout << "kou" << endl;
    }
    else if(ans1 - a[0] + a[n - 1] == ans2 - a[n - 1] + a[0]){
        cout << "draw" << endl;
    }
    else {
        cout << "yukari" << endl;
    }

    
    
}

int main(){
    int t;
    cin >> t;

    while(t --) solve();
}