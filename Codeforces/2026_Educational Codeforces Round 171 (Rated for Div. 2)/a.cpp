#include <bits/stdc++.h>

using namespace std;

void solve(){
    int x, y, k;
    cin >> x >> y >> k;

    int ax, ay, bx, by;
    int cx, cy, dx, dy;

    ax = 0, ay = 0;
    bx = min(x, y), by = min(x, y);
    
    cx = x, cy = 0;
    dx = x - min(x, y), dy = min(x, y);
    cout << ax << " " << ay << " " << bx << " " << by << endl << cx << " " << cy << " " << dx << " " << dy << endl;
}

int main(){
    int t;
    cin >> t;

    while(t --){
        solve();
    }
}