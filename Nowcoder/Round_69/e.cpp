#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 10;

int a[N], s[N], b[N];
int cnt[N];

signed main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        b[i] = b[i - 1] + (a[i] > 0);
    }

    if(s[n] % 3 != 0 || b[n] < 3){
        cout << 0 << endl;
        return 0;
    }

    int t1 = 0, t2 = 0, ans = 0;
    
    for(int i = 1; i <= n; i ++){
        if(s[i] == s[n] / 3 && b[i] > 0 && b[i] < b[n] - 1){
            t1 ++;
            cnt[b[i]] ++;
        }
    }
    
    for(int i = 1; i <= n; i ++){
        if(s[i] == s[n] / 3 * 2 && b[i] > 1){
            for(int j = 0; j <= b[i] - 1; j ++){
//                 cout << "j" << j << " ";
                ans += cnt[j];
            } 
        }
    }
//     for(int i = 0; i < n; i ++){
//         cout << s[i] << " ";
//     }
//     cout << endl;
    
//     for(int i = 0; i < n; i ++){
//         cout << a[i] << " ";
//     }
//     cout << endl;
    
//     for(int i = 0; i < n; i ++){
//         cout << b[i] << " ";
//     }
//     cout << endl;
    
//     for(int i = 0; i < n; i ++){
//         cout << cnt[i] << " ";
//     }
//     cout << endl;
    cout << ans << endl;
}