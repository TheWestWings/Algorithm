#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int N = 200010;

struct Node {
    int l, r;
    double sum; // 区间总水量
    double set; // 懒惰标记，-1表示无标记
} tr[N * 4];

double a[N];

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u) {
    if (tr[u].set != -1) {
        double val = tr[u].set;
        tr[u << 1].set = val;
        tr[u << 1 | 1].set = val;
        int mid = (tr[u].l + tr[u].r) >> 1;
        tr[u << 1].sum = val * (mid - tr[u].l + 1);
        tr[u << 1 | 1].sum = val * (tr[u].r - mid);
        tr[u].set = -1;
    }
}

void build(int u, int l, int r) {
    tr[u] = {l, r, 0, -1};
    if (l == r) {
        tr[u].sum = a[l];
    }
    else {
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid+1, r);
        pushup(u);
    }
}

double query_sum(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].sum;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    double sum = 0;
    if (l <= mid) sum += query_sum(u << 1, l, r);
    if (r > mid) sum += query_sum(u << 1 | 1, l, r);
    return sum;
}

void modify(int u, int l, int r, double val) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum = val * (tr[u].r - tr[u].l + 1);
        tr[u].set = val;
        return;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid) modify(u << 1, l, r, val);
    if (r > mid) modify(u << 1 | 1, l, r, val);
    pushup(u);
}

double query_point(int u, int pos) {
    if (tr[u].l == tr[u].r) {
        return tr[u].sum;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (pos <= mid) return query_point(u << 1, pos);
    else return query_point(u << 1 | 1, pos);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%lf", &a[i]);
    }
    build(1, 1, n);
    while(m--) {
        int op;
        scanf("%d", &op);
        if(op == 1) {
            int l, r;
            scanf("%d %d", &l, &r);
            double total = query_sum(1, l, r);
            double avg = total / (r - l + 1);
            modify(1, l, r, avg);
        }
        else if(op == 2) {
            int i;
            scanf("%d", &i);
            double res = query_point(1, i);
            printf("%.5f\n", res);
        }
    }
    return 0;
}