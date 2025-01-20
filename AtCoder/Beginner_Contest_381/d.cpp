#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int a[N];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    int ans = 0;
    map<int, int> mp;
    queue<int> q;
    for(int i = 0; i < n - 1; i ++){
        if(a[i] != a[i + 1]){
            mp.clear();
            while(!q.empty()) q.pop();
            continue;
        }
        while(mp.count(a[i])){
            mp.erase(q.front());
            q.pop();
        }
        
        mp[a[i]] ++;
        q.push(a[i]);
        int s = q.size();
        ans = max(ans, s);
        i ++;
    }
    cout << ans * 2 << endl;
}