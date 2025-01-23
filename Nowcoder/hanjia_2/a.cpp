#include <bits/stdc++.h>

using namespace std;



int main(){
    map<int, int> mp;

    for(int i = 0; i < 7; i ++){
        int x;
        cin >> x;

        mp[x] ++;
    }

    if(mp[4] != 0 || mp[7] != 0) cout << "NO" << endl;
    else cout << "YES" << endl;

}