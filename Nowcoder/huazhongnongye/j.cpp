#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 查询结构体：存储需求值 a, 天数 t, 查询索引 idx
struct Query {
    int a;
    int t;
    int idx;
};

// 线段树结构体：支持区间最小值查询和单点更新
struct SegmentTree {
    int n;
    vector<ll> tree;
    SegmentTree(int size){
        n = 1;
        while(n < size) n <<=1;
        tree.assign(2*n, 1e18);
    }
    // 更新某个位置的值
    void update(int pos, ll val){
        pos += n;
        tree[pos] = val;
        while(pos >1){
            pos >>=1;
            tree[pos] = min(tree[2*pos], tree[2*pos+1]);
        }
    }
    // 查询区间 [l, r] 的最小值
    ll query(int l, int r){
        l +=n;
        r +=n;
        ll res = 1e18;
        while(l <= r){
            if(l%2 ==1){
                res = min(res, tree[l++]);
            }
            if(r%2 ==0){
                res = min(res, tree[r--]);
            }
            l >>=1;
            r >>=1;
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<ll> v(n);
        for(auto &x:v) cin>>x;
        vector<ll> c(n);
        for(auto &x:c) cin>>x;
        vector<int> a(n);
        for(auto &x:a) cin>>x;
        // 构建商品列表：[价值, [花费, 索引]]
        vector<pair<ll, pair<ll, int>>> items(n);
        for(int i=0;i<n;i++) items[i] = {v[i], {c[i], i}};
        // 按价值从高到低排序，如果价值相同，则按花费从低到高
        sort(items.begin(), items.end(), [&](const pair<ll, pair<ll, int>> &a, const pair<ll, pair<ll, int>> &b)->bool{
            if(a.first != b.first) return a.first > b.first;
            return a.second.first < b.second.first;
        });
        // 构建查询列表
        vector<Query> queries(n);
        for(int i=0;i<n;i++) queries[i] = {a[i], i, i};
        // 按 a 从高到低排序，如果 a 相同，则按天数从小到大
        sort(queries.begin(), queries.end(), [&](const Query &a, const Query &b)->bool{
            if(a.a != b.a) return a.a > b.a;
            return a.t < b.t;
        });
        // 初始化线段树
        SegmentTree st(n);
        // 结果数组，初始化为 -1
        vector<ll> ans(n, -1);
        int ptr=0;
        for(auto &q: queries){
            // 将所有价值 >= a_t 的商品加入线段树
            while(ptr < n && items[ptr].first >= q.a){
                ll cost = items[ptr].second.first;
                int idx = items[ptr].second.second;
                st.update(idx, cost);
                ptr++;
            }
            // 查询在 [t, n-1] 范围内的最小 c_i
            ll res = st.query(q.t, n-1);
            if(res != 1e18){
                ans[q.idx] = res;
                // 找到该 c_i 的位置
                int l = q.t, r = n-1;
                int pos = -1;
                while(l <= r){
                    int mid = l + (r-l)/2;
                    if(st.query(mid, mid) == res){
                        pos = mid;
                        break;
                    }
                    // 尝试缩小范围
                    if(st.query(l, mid) == res){
                        r = mid;
                    }
                    else{
                        l = mid+1;
                    }
                }
                if(pos != -1){
                    st.update(pos, 1e18); // 标记为已购买
                }
            }
        }
        // 输出答案
        for(int i=0;i<n;i++) cout << ans[i] << (i<n-1?" ":"\n");
    }
}