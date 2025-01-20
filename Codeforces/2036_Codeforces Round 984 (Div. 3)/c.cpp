#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_K = 100005;
const int MAX_N = 100005;

int n, k, q;
vector<int> a[MAX_K];
vector<pair<int, int>> changes[MAX_K];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> q;

    // 读取输入并初始化
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            int val;
            if (i == 1) a[j].resize(n + 2);
            cin >> val;
            a[j][i] = val;
        }
    }

    // 预处理每个区域的变化点
    for (int j = 1; j <= k; ++j) {
        int b = 0;
        for (int i = 1; i <= n; ++i) {
            int b_new = b | a[j][i];
            if (b_new != b) {
                b = b_new;
                changes[j].emplace_back(i, b);
            }
        }
    }

    while (q--) {
        int m;
        cin >> m;
        int Max_first_i = 1;
        int Min_last_i = n;

        for (int i = 0; i < m; ++i) {
            int r, c;
            char o;
            cin >> r >> o >> c;
            auto& cp = changes[r];

            if (o == '<') {
                // 查找最大的 i 满足 b_{i,r} < c
                int left = 0, right = cp.size() - 1;
                int pos = -1;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (cp[mid].second < c) {
                        pos = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if (pos != -1) {
                    int last_i = cp[pos].first;
                    Min_last_i = min(Min_last_i, last_i);
                } else {
                    Min_last_i = 0;
                }
            } else {
                // 查找最小的 i 满足 b_{i,r} > c
                int left = 0, right = cp.size() - 1;
                int pos = -1;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (cp[mid].second > c) {
                        pos = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                if (left < cp.size()) {
                    int first_i = cp[left].first;
                    Max_first_i = max(Max_first_i, first_i);
                } else {
                    Max_first_i = n + 1;
                }
            }
        }

        if (Max_first_i <= Min_last_i) {
            cout << Max_first_i << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}