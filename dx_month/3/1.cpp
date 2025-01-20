#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int t[N];
int st[3];
int n;
string color;

bool check(int x){
    memset(st, 0, sizeof st);
    int last = -1;
    for(int i = 0; i < n; i ++){
        if(t[i] <= x){
            continue;
        }
        else{
            if(last == -1){
                last = color[i] - '0';
                st[color[i] - '0'] ++;
                continue;
            }
            if(st[color[i] - '0'] && last != color[i] - '0'){
                return false;
            }
            st[color[i] - '0'] ++;
            last = color[i] - '0';
        }
    }
    return true;
}

int main(){
    cin >> n;
    cin >> color;

    for(int i = 0; i < n; i ++){
        cin >> t[i];
    }

    int l = 0, r = 1e9, ans = 0;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)){
            ans = mid;
            r = mid;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
}