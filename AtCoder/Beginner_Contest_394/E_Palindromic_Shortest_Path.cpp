#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
using namespace std;
 
const int INF = numeric_limits<int>::max();
 
struct State {
    int u, v, cost;
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++){
        cin >> grid[i];
    }
 
    // 构建每个顶点的入边列表
    // inEdges[v] 存储满足 u->v 有边且标签为 letter 的 (u, letter)
    vector<vector<pair<int, char>>> inEdges(n);
    for (int u = 0; u < n; u++){
        for (int v = 0; v < n; v++){
            char c = grid[u][v];
            if(c != '-')
                inEdges[v].push_back({u, c});
        }
    }
 
    // dp[u][v] 存储从顶点 u 到 v 的最短回文路径的长度
    vector<vector<int>> dp(n, vector<int>(n, INF));
 
    queue<State> q;
 
    // 基础状态：
    // (i, i) 表示空路径，长度为 0。
    for (int i = 0; i < n; i++){
        dp[i][i] = 0;
        q.push({i, i, 0});
    }
    // 对每个存在的边 i->j，路径长度为 1（单个字母本身是回文）
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(grid[i][j] != '-' && dp[i][j] > 1){
                dp[i][j] = 1;
                q.push({i, j, 1});
            }
        }
    }
 
    // 在状态空间 (u,v) 内进行 BFS 搜索
    // 状态 (x, y) 表示已经存在从 x 到 y 的回文路径，cost 为当前路径的长度
    while(!q.empty()){
        auto st = q.front();
        q.pop();
 
        // 如果当前状态的 cost 已经不是记录的最小值，则跳过
        // if (st.cost != dp[st.u][st.v])
        //     continue;
 
        // 尝试扩展状态 (x, y)，两端同时扩展
        int x = st.u, y = st.v;
 
        // 遍历所有以 x 为终点的入边
        for (auto &inPair : inEdges[x]){
            int u = inPair.first;
            char letter = inPair.second;
            // 遍历 y 出边中的所有边，看是否与当前字母匹配
            for (int v = 0; v < n; v++){
                if(grid[y][v] == letter){
                    int newCost = st.cost + 2;
                    if(newCost < dp[u][v]){
                        dp[u][v] = newCost;
                        q.push({u, v, newCost});
                    }
                }
            }
        }
    }
 
    // 最终输出每个顶点对的答案
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(dp[i][j] == INF) cout << -1;
            else cout << dp[i][j];
            if(j < n - 1) cout << " ";
        }
        cout << "\n";
    }
 
    return 0;
}