#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 10;

vector<int> a(N);

signed main(){
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    
//     for(int i = 0; i < a.size(); i ++){
//         cout << a[i] << " ";
//     }
//     cout << endl;

    int i = 0, j = 0, now = 0;
    int ans = 0;
    for(int i = 1; i < a.size() - ans; i ++){
        int l = 0, r = a.size() + k;
        while(l < r){
            int mid = l + r + 1 >> 1;
            j = mid + i - 1 - k;
            if(mid >= a[j] - a[i] + 1){
                ans = max(ans, mid);
                l = mid;
            }
            else{
                r = mid - 1;
            }
            // cout << l << " " << r << endl;
        }
//         for(int j = i + ans; j < a.size(); j ++){
//             if(j - i + 1 + k >= a[j] - a[i] + 1){
//                 ans = j - i + 1 + k;
// //                 cout << i << " " << j << " " << ans << endl;
// //                 cout << a[j] << " " << a[i] << endl;
//             }
//             else{
//                 break;
//             }
//         }
    }
    

    cout << min(ans, min(n + k, m))<< endl;
}