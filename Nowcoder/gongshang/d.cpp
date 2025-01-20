#include <bits/stdc++.h>

using namespace std;

void solve(){
    char str[1000];
    gets(str);
    int n = strlen(str);

    stack<char> st;
    for(int i = 0; i < n - 3; i ++){
        if(str[i] == 'l' && str[i + 1] == 'j' && str[i + 2] == 'l'){
            st.push('n');
            st.push('c');
            st.push('l');
            st.push('j');
            st.push('r');
            i += 2;
        }
        else{
            st.push(str[i]);
        }
    }

    vector<char> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    for(int i = ans.size() - 1; i >= 0; i --){
        cout << ans[i];
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    cout << t << endl;

    while(t --){
        solve();
    }
}