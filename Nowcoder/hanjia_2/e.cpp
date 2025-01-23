#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5 + 10;

int a[N], s[N];

template<class Info, class Tag>
struct LazySegmentTree {
#define mid ((l+r)>>1)
    int n;
    vector<Info> info;
    vector<Tag> tag;
    LazySegmentTree() :n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(vector<Info>(n_, v_));
    }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << (int)log2(n + 1), Info());
        tag.assign(4 << (int)log2(n + 1), Tag());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r) {
                info[p] = init_[l];
                return;
            }
            build(2 * p, l, mid);
            build(2 * p + 1, mid + 1, r);
            pushup(p);
            };
        build(1, 0, n - 1);
    }
    void pushup(int p) {
        info[p] = info[p * 2] + info[p * 2 + 1];
    }
    void apply(int p, const Tag& v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void pushdown(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void update(int p, int l, int r, int x, const Info& v) {
        if (l == r) {
            info[p] = v;
            return;
        }
        pushdown(p);
        if (x <= mid) update(p * 2, l, mid, x, v);
        else update(p * 2 + 1, mid + 1, r, x, v);
        pushup(p);
    }
    void update(int p, const Info& v) {
        update(1, 0, n - 1, p, v);
    }
    Info query(int p, int l, int r, int x, int y) {
        if (l >= x && r <= y)
            return info[p];
        pushdown(p);
        if (y <= mid)
            return query(2 * p, l, mid, x, y);
        if (x > mid)
            return query(2 * p + 1, mid + 1, r, x, y);
        return query(2 * p, l, mid, x, y) + query(2 * p + 1, mid + 1, r, x, y);
    }
    Info query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag& v) {
        if (l > y || r < x) return;
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        pushdown(p);
        rangeApply(2 * p, l, mid, x, y, v);
        rangeApply(2 * p + 1, mid + 1, r, x, y, v);
        pushup(p);
    }
    void rangeApply(int l, int r, const Tag& v) {
        return rangeApply(1, 0, n - 1, l, r, v);
    }
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F pred) {
        if (l > y || r < x || !pred(info[p])) return -1;
        if (r == l) return l;
        pushdown(p);
        int res = findFirst(2 * p, l, mid, x, y, pred);
        if (res == -1) res = findFirst(2 * p + 1, mid + 1, r, x, y, pred);
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F pred) {
        return findFirst(1, 0, n - 1, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F pred) {
        if (l > y || r < x || !pred(info[p])) return -1;
        if (r == l) return l;
        pushdown(p);
        int res = findLast(2 * p + 1, mid + 1, r, x, y, pred);
        if (res == -1) res = findLast(2 * p, l, mid, x, y, pred);
        return res;
    }
    template<class F>
    int findLast(int l, int r, F pred) {
        return findLast(1, 0, n - 1, l, r, pred);
    }
};

struct Tag {
    ll add;
    void apply(Tag t) {
        add += t.add;
    }
};

struct Info {
    ll sum;
    void apply(Tag t) {
        
    }
};

Info operator+(Info a, Info b) {
    return { max(a.sum, b.sum) };
}

int main() {
    int n, q;
    cin >> n >> q;

    // 输入数组 a 并计算前缀和 s
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    
    vector<Info> info(n + 1);
    for (int i = 1; i <= n; i++) {
        // modify(1, i, a[i] - s[i - 1]);
        info[i].sum = a[i] - s[i - 1];
        // cout << query(1, i, i) << endl;
        // cout << tr[i].v << endl;
        cout << info[i].sum << " ";
    }

    LazySegmentTree<Info, Tag> st(info);
    // cout << st.query(2, 2).sum << endl;

    // 处理查询
    while (q--) {
        int l, r;
        cin >> l >> r;

        int max_val = l + 1 > r ? -1e18 :st.query(l + 1, r).sum;
        // cout << max_val << endl;
        int result = max_val + s[l - 1];

        if (result < 0) {
            cout << 0 << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}