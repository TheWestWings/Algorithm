#include <bits/stdc++.h>

using namespace std;

bool solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n - 1);

    for (int i = 0; i < n; i++) {
        scanf("%1d", &a[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        scanf("%1d", &b[i]);
    }

    list<int> lst(a.begin(), a.end());
    auto it = lst.begin();
    int j = 0;

    while (lst.size() > 1 && j < b.size()) {
        auto next_it = next(it);
        if (next_it == lst.end()) break;

        if (*it != *next_it) {
            // 删除下一个元素并替换当前元素
            next_it = lst.erase(next_it);
            *it = b[j++];
            if (it != lst.begin()) {
                --it;
            }
        } else {
            ++it;
        }
    }

    if (lst.size() == 1)
        return true;
    else
        return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}