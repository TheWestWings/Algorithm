#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 10;

int mp[N];

int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;

    int res = 0, cnt = 1;
    vector<int> v;
    
    for(int i = 1; i < n; i ++){
        if(str[i] == str[i - 1]){
            cnt ++;
        }
        else{
            // v.push_back(cnt);
            mp[cnt] ++;
            cnt = 1;
        }
    }
    mp[cnt] ++;

    // for(auto x : mp){
    //     cout << x.first << " " << x.second << endl;
    // }

    int last = 0;
    int s = 0;
    int ss = 0;
    for(int i = n; i >= 1; i --){
        // res = res ^ (i * (last + (n - mp[i])))
        // int t = 0;
        // for(int j = i + 1; j <= n; j ++){
        //     t += (j - i) * mp[j];
        //     if(mp[j] == 0) break;   
        // }
        
        // cout << i << " " << t << " " << s << " " << mp[i] <<endl;
        ss += mp[i];
        if(i == n) res = (i * (n - s));
        else res = res ^ (i * (n - s));
        s += ss ; 
        // res = res ^ (i * (n - t));
    }
    cout << (res) << endl;
} 