#include <bits/stdc++.h>

using namespace std;

const int N = 110;
typedef long long ll;
typedef pair<int, int> PII;

PII a[N];

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> a[i].first >> a[i].second;
    }

    int q;
    cin >> q;

    while(q --){
        int x, y;
        cin >> x >> y;

        if(y % a[x].first > a[x].second){
            cout << y + a[x].first - (y % a[x].first - a[x].second) << endl;
        }
        else{
            cout << y + (a[x].second - y % a[x].first) << endl;
        }

    }
}