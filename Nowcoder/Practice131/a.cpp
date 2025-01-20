#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
typedef long long ll;
typedef pair<ll, ll> PII;

PII a[N];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a, a + n);

    ll cnt = 0;
    ll ans = 0;
    ll mn = 0x3f3f3f3f;
    ll ans_i = -1;

    // for(int i = 0; i < n; i ++){
    //     cout << a[i].first << " ";
    // }
    // cout << endl;

    vector<ll> ans_list;
    for(int i = 0; i < n; i ++){
        if((n - i) * (n - i) * a[i].first > ans){
            ans = (n - i) * (n - 1) * a[i].first;
            cnt = n - i - 1;
            mn = a[i].first;
            ans_i = i;
        }
    }

    for(int i = ans_i; i < n; i++){
        ans_list.push_back(a[i].second);   
    }
    
    sort(ans_list.begin(), ans_list.end());

    cout << ans_list.size() << endl;
    for(int i = 0; i < ans_list.size(); i++){
        cout << ans_list[i] << " ";
    }
    
}