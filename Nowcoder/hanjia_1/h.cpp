#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

vector<pair<PII, int>> a;

bool st[N];

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i ++){
        int l, r;
        cin >> l >> r;
        a.push_back({{l, r}, i});
    }

    sort(a.begin(), a.end(), [](pair<PII, int> a, pair<PII, int> b){
        if(a.first.first == b.first.first){
            return a.first.second - a.first.first == b.first.second - b.first.first;
        }
        return a.first.first < b.first.first;
    });

    for(int i = 0; i < n; i ++){
        cout << a[i].first.first << " " << a[i].first.second << " " << a[i].second << endl;
    }

    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i ++){
        bool flag = false;
        for(int j = a[i - 1].first.first; j <= a[i - 1].first.second; j ++){
            if(!st[j]){
                ans[a[i - 1].second] = j;
                st[j] = true;
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << -1 << endl;
            return 0;
        }
    }

    for(int i = 1; i <= n; i ++){
        cout << ans[i] << " ";
    }
}