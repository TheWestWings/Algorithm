#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    string S;
    cin >> N >> K >> S;

    // 找到所有的 '1' 块的起始和结束位置
    vector<pair<int, int>> blocks;
    int start = -1;
    for(int i = 0; i < N; i++){
        if(S[i] == '1'){
            if(start == -1){
                start = i;
            }
            if(i == N-1){
                blocks.emplace_back(make_pair(start, i));
            }
        }
        else{
            if(start != -1){
                blocks.emplace_back(make_pair(start, i-1));
                start = -1;
            }
        }
    }

    // 保证至少有 K 个 '1' 块
    if(blocks.size() < K){
        cout << S << endl;
        return 0;
    }

    // 获取第 K 个 '1' 块和第 (K-1) 个 '1' 块的位置
    pair<int, int> target = blocks[K-1];
    pair<int, int> insert_after = (K == 1) ? make_pair(-1, -1) : blocks[K-2];

    // 构建新的字符串 T
    string T = "";

    // 添加第 1 到 (K-1) 个 '1' 块之前的部分
    if(insert_after.first != -1){
        T += S.substr(0, insert_after.second + 1);
    }

    // 添加第 K 个 '1' 块
    T += S.substr(target.first, target.second - target.first + 1);

    // 添加第 K 个 '1' 块后到下一个块之前的 '0's
    int zeros_start = (insert_after.first != -1) ? insert_after.second + 1 : 0;
    int zeros_length = target.first - zeros_start;
    if(zeros_length > 0){
        T += S.substr(zeros_start, zeros_length);
    }

    // 添加其余部分
    T += S.substr(target.second + 1, N - target.second - 1);

    cout << T << endl;
}