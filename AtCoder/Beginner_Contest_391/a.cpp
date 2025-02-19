#include <bits/stdc++.h>

using namespace std;

int main(){
    map<string, string> mp;
    string str;
    cin >> str;

    mp["N"] = "S";
    mp["E"] = "W";
    mp["S"] = "N";
    mp["W"] = "E";
    mp["NE"] = "SW";
    mp["NW"] = "SE";
    mp["SE"] = "NW";
    mp["SW"] = "NE";

    cout << mp[str] << endl;
}