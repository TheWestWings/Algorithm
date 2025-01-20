#include <bits/stdc++.h>

using namespace std;

const int N = 1010, M = 15;

int a[N];
int b[M];
int c[M][30];

int two_ten(string str){
    int res = 0;
    for(int i = 0; i < str.size(); i ++){
        res = res * 2 + str[i] - '0';
    }
    return res;
}

int cnt(int x){
    int res = 0;
    while(x){
        if(x & 1) res ++;
        x >>= 1;
    }
    return res;
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i ++){
        string str;
        cin >> str;
        a[i] = two_ten(str);
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i ++){
        string str;
        cin >> str;
        b[i] = two_ten(str);
    }

    for(int i = 0; i < n; i ++){
        int x = a[i];
        int ans = 0x3f3f3f;
        for(int st = 0; st < (1 << k); st ++){
            int y = 0;
            for(int j = 0; j < k; j ++){
                if(st & (1 << j)) y |= b[j];
            }
            if((x & y) == x){
                ans = min(ans,  cnt(st));
            }
        }
        cout << (ans == 0x3f3f3f ? -1 : ans) << endl;
    }
}