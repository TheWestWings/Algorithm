#include <bits/stdc++.h>

using namespace std;

const int MAXN = 705;
const int MAXM = 500005;

int n, m, K;
int a[MAXN][MAXN];
int arr[MAXN * MAXN];
int coords[MAXN * MAXN][2];

int cntColor = 0; // ��ɢ�������ɫ����

struct Query {
    int id;
    int x1, y1, x2, y2;
    int ord;

    // Hilbert order
    int64_t getHilbertOrder() const {
        int64_t x = x1, y = y1;
        int64_t d = 0;
        for (int s = 1 << 20; s > 0; s >>= 1) {
            bool rx = x & s;
            bool ry = y & s;
            d += s * s * ((3 * rx) ^ ry);
            if (!ry) {
                if (rx) {
                    x = s - 1 - x;
                    y = s - 1 - y;
                }
                swap(x, y);
            }
        }
        return d;
    }

    bool operator<(const Query& other) const {
        return ord < other.ord;
    }
};

vector<Query> queries;
int res[MAXM];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> K;

    map<int, int> colorMap;
    int idx = 0;

    // ��ȡ����ɢ����ɫ
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int c;
            cin >> c;
            if (colorMap.find(c) == colorMap.end()) {
                colorMap[c] = ++cntColor;
            }
            a[i][j] = colorMap[c];
            arr[idx] = a[i][j];
            coords[idx][0] = i;
            coords[idx][1] = j;
            idx++;
        }
    }

    // չ����ά����Ϊһά����
    int N = n * n;

    // ����һάλ�õ���ά�����ӳ��
    auto getID = [&](int x, int y) {
        return (x - 1) * n + (y - 1);
    };

    // ��ȡ��ѯ��ת��Ϊ����
    queries.resize(m);
    for (int i = 0; i < m; ++i) {
        int x_i, y_i;
        cin >> x_i >> y_i;
        int x1 = x_i, y1 = y_i;
        int x2 = x_i + K - 1, y2 = y_i + K -1;
        queries[i] = {i, x1, y1, x2, y2, 0};
    }

    // ����ÿ����ѯ�� Hilbert ��
    int maxC = max(n, n);
    for (auto& q : queries) {
        q.ord = q.getHilbertOrder();
    }

    // ���� Hilbert �������ѯ
    sort(queries.begin(), queries.end());

    // ��ʼ��������
    vector<int> cnt(cntColor + 1, 0);
    int ans = 0;

    // ��ʼ��ָ��λ��
    int currLx = 1, currLy = 1, currRx = 0, currRy = 0;

    // ������Ӻ�ɾ������
    auto add = [&](int x, int y) {
        int c = a[x][y];
        cnt[c]++;
        if (cnt[c] == 2) ans++;
    };

    auto remove = [&](int x, int y) {
        int c = a[x][y];
        cnt[c]--;
        if (cnt[c] == 1) ans--;
    };

    for (auto& q : queries) {
        int Lx = q.x1, Ly = q.y1, Rx = q.x2, Ry = q.y2;

        // ��չ��Ŀ������
        while (currRx < Rx) {
            currRx++;
            for (int y = currLy; y <= currRy; ++y) {
                add(currRx, y);
            }
        }
        while (currRy < Ry) {
            currRy++;
            for (int x = currLx; x <= currRx; ++x) {
                add(x, currRy);
            }
        }

        // ��С��Ŀ������
        while (currLx > Lx) {
            currLx--;
            for (int y = currLy; y <= currRy; ++y) {
                add(currLx, y);
            }
        }
        while (currLy > Ly) {
            currLy--;
            for (int x = currLx; x <= currRx; ++x) {
                add(x, currLy);
            }
        }

        // �Ƴ����������
        while (currRx > Rx) {
            for (int y = currLy; y <= currRy; ++y) {
                remove(currRx, y);
            }
            currRx--;
        }
        while (currRy > Ry) {
            for (int x = currLx; x <= currRx; ++x) {
                remove(x, currRy);
            }
            currRy--;
        }

        while (currLx < Lx) {
            for (int y = currLy; y <= currRy; ++y) {
                remove(currLx, y);
            }
            currLx++;
        }
        while (currLy < Ly) {
            for (int x = currLx; x <= currRx; ++x) {
                remove(x, currLy);
            }
            currLy++;
        }

        res[q.id] = ans;
    }

    // ���ղ�ѯ��ԭʼ˳��������
    for (int i = 0; i < m; ++i) {
        cout << res[i] << "\n";
    }

    return 0;
}