#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    string str;
    cin >> str;
    for(int i = 0; i < n; i++){
        a[i] = str[i] - 'a';
    }

    // for(auto x : a){
    //     cout << x << " ";
    // }

    int ans = 0;
    for(int i = 25; i >= 1; i --){
        for(int j = 0; j < n; j ++){
            // cout << char(i + 'a') << " " << char(a[j] + 'a') << endl;
            if(a[j] == i && ((j > 0 && a[j - 1] == i - 1) || (j < n - 1 && a[j + 1] == i - 1))){
                // cout << char(a[j] + 'a') << endl;
                ans ++;
                a.erase(a.begin() + j);
                n --;
                j = 0;
                // cout << "n = " << n << endl;
            }   
        }
        // for(auto it = a.begin(); it != a.end(); it++){
        //     cout << char(*it + 'a');
        // }
    }
    cout << ans << endl;
    // for(auto it = a.begin(); it != a.end(); it++){
    //     cout << char(*it + 'a');
    // }
    // for(auto x : a){
    //     cout << char(x + 'a');
    // }

}