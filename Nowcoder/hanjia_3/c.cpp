#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int tire[N][26],cnt[N],idx, t = 0;
bool st[N];
vector<string> a;
string new_str = "";

void insert(string str){
    int p=0;
    for(auto i=0;i<str.size();i++){
        int u=str[i]-'a';
        if(tire[p][u]==0){
            tire[p][u]=++idx;
        } 
        p=tire[p][u];
    }
    cnt[p]++;
}


int query(string str){
    // cout << str << endl;
    int p=0;
    int ans = 0;
    for(auto i = 0;i < str.size(); i++){
        int u=str[i]-'a';
        if(!st[tire[p][u]]){
            ans ++;
            st[tire[p][u]] = true;
        }
        p=tire[p][u];
    }
    // cout << ans << endl;
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;

    
    for(int i = 0; i < n; i ++){
        string str;
        cin >> str;
        a.push_back(str);

        insert(str);
    }

    sort(a.begin(), a.end(), [](string a, string b){
        return a.size() < b.size();
    });

    int l, r;
    cin >> l >> r;

    int last = 0;
    
    int ans = 0;
    for(int i = 0; i < n; i ++){
        int t = query(a[i]);
        // cout << t << endl;
        ans += 2 * t;
    }

    
    cout << ans - a[a.size() - 1].size()<< endl;
}