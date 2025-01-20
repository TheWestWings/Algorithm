#include <bits/stdc++.h>

using namespace std;

const int N = 10;

vector<vector<int>> a;

int main(){
    int n, m, q;
    cin >> n >> m >> q;

    a.resize(n, vector<int>(m));
    for(int i = 0; i < n; i ++){
        string str;
        cin >> str;
        // cout << str << endl;
        for(int j = 0; j < m; j ++){
            a[i][j] = str[j] == '1' ? 0 : 1;
        }
    }

    vector<vector<vector<int>>> b(q, vector<vector<int>>(n, vector<int>(m)));
    for(int k = 0; k < q; k ++){
        for(int i = 0; i < n; i ++){
            string str;
            cin >> str;
            for(int j = 0; j < m; j ++){
                b[k][i][j] = str[j] - '0';
            }
        }
    }

    vector<pair<int, vector<int>>> ans;
    for(int k = 0; k < (1 << q); k ++){
        vector<vector<int>> c(n, vector<int>(m));
        // cout << "--------------------------------" << endl;
        for(int t = 0; t < q; t ++){
            if(k & (1 << t)){
                for(int i = 0; i < n; i ++){
                    for(int j = 0; j < m; j ++){
                        c[i][j] |= b[t][i][j];
                    }
                }
            }
        }
        // for(int i = 0; i < n; i ++){
        //     for(int j = 0; j < m; j ++){
        //         cout << c[i][j];
        //     }
        //     cout << endl;
        // }
        bool flag = true;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(c[i][j] != a[i][j]){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag){
            continue;
        }
        ans.push_back({__builtin_popcount(k), vector<int>()});
        for(int t = 0; t < q; t ++){
            if(k & (1 << t)){
                ans.back().second.push_back(t + 1);
            }
        }
    }

    sort(ans.begin(), ans.end());
    if(ans.empty()){
        cout << -1 << endl;
    }
    else{
        cout << ans[0].first << endl;
        for(int i = 0; i < ans[0].first; i ++){
            cout << ans[0].second[i] << " ";
        }
    }
}