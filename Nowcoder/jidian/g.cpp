#include <bits/stdc++.h>
#define x first
#define y second
#define int long long

using namespace std;

const int N = 2e5 + 10;
typedef pair<int, int> PII;


struct rabbit
{
    int x, y, w;
}r[N];


int a[N];

bool cmp(struct rabbit a, struct rabbit b){
    return a.w * b.y < b.w * a.y;
}

signed main(){
    int n, k;
    cin >> n >> k;

    int s = 0;
    for(int i = 1; i <= n; i ++){
        cin >> r[i].x >> r[i].y;
        s += r[i].y;
    }

    for(int i = 1; i <= n; i ++){
        r[i].w = (r[i].x + k - 1) / k; 
    }

    sort(r + 1, r + n + 1, cmp);
    
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        ans += (r[i].x + k - 1) / k * s;
        s -= r[i].y;
    }

    cout << ans << endl;

    

}