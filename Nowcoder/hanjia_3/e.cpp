#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
typedef pair<int, int> PII;

PII a[N];

int main(){
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n, [](PII a, PII b){
        return a.first < b.first;
    });

    int cnt = 0;
    int total = 0;
    bool flag = false;
    multiset<double> s;
    for(int i = 0; i < n; i ++){
        if(a[i - 1].second < 0 && a[i].second > 0 && flag){
            cout << cnt << " " << i << endl;
            total += cnt - 1;
            cnt = 0;
            flag = false;
        }
        if(a[i].second > 0){
            cnt ++;
            flag = true;
        }
        if(a[i].second < 0 && flag){
            cnt ++;
        }

    }   
    if(flag){
        total += cnt - 1;
    }
    cout << total << endl;
}