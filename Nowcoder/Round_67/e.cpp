#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int T;
string L_str, R_str;
int len;
map<tuple<int, bool, bool>, int> dp;

int dfs(int pos, bool tight_low, bool tight_high) {
    if (pos == len) return 0;

    auto key = make_tuple(pos, tight_low, tight_high);
    if (dp.count(key)) return dp[key];

    int res = 0;
    char low = tight_low ? L_str[pos] : '0';
    char high = tight_high ? R_str[pos] : '9';

    for (char d = high; d >= low; d--) {
        bool new_tight_low = tight_low && (d == low);
        bool new_tight_high = tight_high && (d == high);
        int sum_dfs = (d - '0') + dfs(pos + 1, new_tight_low, new_tight_high);
        res = max(res, sum_dfs);
        // 因为我们要找到最大的数位和，所以可以直接break
        if (res == (d - '0') + (len - pos - 1) * 9) break;
    }

    dp[key] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        ll L = l1 + l2;
        ll R = r1 + r2;
        L_str = to_string(L);
        R_str = to_string(R);
        len = R_str.size();
        // 补齐L_str的长度
        while (L_str.size() < len) L_str = '0' + L_str;
        dp.clear();
        int ans = dfs(0, true, true);
        cout << ans << '\n';
    }
    return 0;
}