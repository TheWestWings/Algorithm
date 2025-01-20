#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

const int N = 1010;

struct Stu{
    string name;
    int score;
    int time;
}s[N];

int main(){
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i ++){
        cin >> s[i].name;
        int cnt = 0;
        for(int j = 0; j < 6; j ++){
            char op;
            cin >> op;
            if(op == '+'){
                cnt ++;
            }
        }
        s[i].score = cnt;
        cin >> s[i].time;
    }

    sort(s, s + n, [](Stu a, Stu b){
        if(a.score == b.score){
            return a.time < b.time;
        }
        return a.score > b.score;
    });

    for(int i = 0; i < k; i ++){
        cout << s[i].name << endl;
    }
}