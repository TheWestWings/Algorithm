#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct node{
    int start, val, b;
}a[N];

int sum[N];

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++){
        cin >> a[i].start;
    }

    for(int i = 1; i <= n; i ++){
        cin >> a[i].val;
        cin >> a[i].b;
    }

    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; i ++){
        sum[i] = sum[i - 1] + a[i].val;
    }

    
    
}