#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N], b[N];
map<int, int> mp1;
map<int, int> mp2;


int main(){
    int n;

    cin >> n;



    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp1[a[i]] ++;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        mp2[b[i]] ++;
    }

    int cnt1 = 0;
    int cnt2 = 0;
    for(auto mp:mp1){
        if(mp.second > 1){
            cnt1 += mp.second - 1;
            mp.second = 1;
        }
    }

    for(auto mp:mp2){
        if(mp.second > 1){
            cnt2 += mp.second - 1;
            mp.second = 1;
        }
    }

    for(auto mp: mp1){
        if(mp2[mp.first] != 0 && mp.second != 0){
            if(cnt1 > cnt2){
                cnt2 ++;
            }
            else 
                cnt1 ++;
        }
    }
    cout << max(cnt1, cnt2) << endl;

}