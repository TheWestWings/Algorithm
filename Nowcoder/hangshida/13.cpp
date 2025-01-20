#include <bits/stdc++.h>

using namespace std;

bool judge(int x){
    string str = to_string(x);
    int n = str.size();
    for(int i = 0; i < n / 2; i ++){
        if(str[i] != str[n - i - 1]){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> a;
    for(int i = 0; i < 100002; i ++){
        if(judge(i)){
            a.push_back(i);
        }
    }

    sort(a.begin(), a.end());   

    for(int i = 0; i < a.size(); i ++){
        cout << i + 1 << " " << a[i] << endl;
    }
}