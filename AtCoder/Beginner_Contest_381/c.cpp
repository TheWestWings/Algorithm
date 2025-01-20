#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    string str;
    cin >> str;

    int ans = 1;
    for(int i = 0; i < n; i ++){
        if(str[i] == '/'){
            int t1 = 0, t2 = 0;
            for(int j = i + 1; j < n; j ++){
                if(str[j] != '2'){
                    t1 = j - i;
                    break;
                }
                if(j == n - 1) t1 = n - i;
            }

            for(int j = i - 1; j >= 0; j --){
                if(str[j] != '1'){
                    t2 = i - j;
                    break;
                }
                if(j == 0) t2 = i + 1;
            }
            // cout << t1 << " " << t2 << endl;
            ans = max(ans, min(t1, t2));
        }
    }
    if(ans == 1) cout << 1 << endl;
    else cout << (ans - 1) * 2 + 1 << endl;
    
}