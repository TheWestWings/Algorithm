#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int mark[N];

vector<int> v;

int main(){
    int n = 5;

    for(int i = 0; i < n; i ++){
        cin >> mark[i];
    }

    
    cout << "ABCDE" << endl;
    for(int i = 4; i >= 1; i --){
        // vector<int> v;
        dfs(0, i);
    }
}