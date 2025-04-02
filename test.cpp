//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
//#define pb push_back
#define all(v) (v.begin()), v.end()
using namespace std;
typedef long long i64;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, long long> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int, int, int> tiii;
typedef tuple<int, int, int, int> t4i;
typedef tuple<ll, ll, ll> tlll;
typedef tuple<ll, ll, ll, ll> t4l;
typedef array<int, 4> ari4;
typedef array<ll, 4> arl4;
typedef array<ll, 3> arl3;
typedef array<int, 3> ari3;
typedef tuple<double, double, double> tddd;
typedef tuple<double, double, double, double> t4d;
typedef long double ld;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
template<class T> constexpr T lowbit(T x) { return x & (-x); }
template<class T> constexpr void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> constexpr  void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> constexpr T ssqrt(T a) { T res = sqrtl(a); while ((res + 1) * (res + 1) <= a) res++; while (res * res > a) res--; return res; }
constexpr ll get_phi(ll x) { ll res = x; for (int i = 2; i <= sqrt(x); i++) { if (x % i == 0) res = res * (i - 1) / i; while (x % i == 0) x /= i; }if (x != 1) res = res * (x - 1) / x; return res; }
constexpr ll power(ll a, u64 b, ll m) { ll res = 1; while (b) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; }return res; }
struct pair_hash { template <class T1, class T2>std::size_t operator() (const std::pair<T1, T2>& pair) const { return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second); } };
template<typename T> ostream& operator << (ostream& out, const set<T>& obj) { out << "set("; for (auto it = obj.begin(); it != obj.end(); it++) out << (it == obj.begin() ? "" : ", ") << *it; out << ")"; return out; }
template<typename T1, typename T2> ostream& operator << (ostream& out, const map<T1, T2>& obj) { out << "map("; for (auto it = obj.begin(); it != obj.end(); it++) out << (it == obj.begin() ? "" : ", ") << it->first << ": " << it->second; out << ")"; return out; }
template<typename T1, typename T2> ostream& operator << (ostream& out, const pair<T1, T2>& obj) { out << "<" << obj.first << ", " << obj.second << ">"; return out; }
template<typename T> ostream& operator << (ostream& out, const vector<T>& obj) { out << "vector("; for (auto it = obj.begin(); it != obj.end(); it++) out << (it == obj.begin() ? "" : ", ") << *it; out << ")"; return out; }
template<typename T>ostream& operator<<(ostream& out, const multiset<T>& obj) { out << "multiset("; bool first = true;  for (auto& e : obj) { if (!first) out << ", ";    out << e;   first = false; }    out << ")";   return out; }
template<typename K, typename V>ostream& operator<<(ostream& out, const multimap<K, V>& obj) { out << "multimap(";  bool first = true;   for (auto& kv : obj) { if (!first) out << ", "; out << kv.first << ": " << kv.second; first = false; }out << ")";  return out; }
template<typename T>ostream& operator<<(ostream& out, const unordered_set<T>& obj) { out << "unordered_set("; bool first = true; for (auto& e : obj) { if (!first) out << ", "; out << e; first = false; } out << ")"; return out; }
template<typename K, typename V>ostream& operator<<(ostream& out, const unordered_map<K, V>& obj) { out << "unordered_map("; bool first = true; for (auto& kv : obj) { if (!first) out << ", "; out << kv.first << ": " << kv.second; first = false; } out << ")"; return out; }
template<typename T>ostream& operator<<(ostream& out, const deque<T>& obj) { out << "deque("; bool first = true; for (auto& e : obj) { if (!first) out << ", "; out << e; first = false; } out << ")"; return out; }
template<typename T>ostream& operator<<(ostream& out, queue<T> q) { out << "queue("; bool first = true;  while (!q.empty()) { if (!first) out << ", ";    out << q.front(); q.pop(); first = false; } out << ")"; return out; }
template<typename T, typename Container, typename Compare>ostream& operator<<(ostream& out, priority_queue<T, Container, Compare> pq) { out << "priority_queue("; bool first = true; while (!pq.empty()) { if (!first) out << ", "; out << pq.top(); pq.pop(); first = false; }out << ")"; return out; }
template<typename T, size_t N>ostream& operator<<(ostream& out, const array<T, N>& arr) { out << "array("; for (size_t i = 0; i < N; ++i) { if (i > 0) out << ", "; out << arr[i]; } out << ")"; return out; }
template<typename T>ostream& operator<<(ostream& out, stack<T> st) { out << "stack("; bool first = true; while (!st.empty()) { if (!first) out << ", "; out << st.top(); st.pop(); first = false; }out << ")"; return out; }
namespace detail { template<size_t I, class... Ts> struct TuplePrinter { static void print(const tuple<Ts...>& t, ostream& out) { TuplePrinter<I - 1, Ts...>::print(t, out); out << ", " << get<I>(t); } }; template<class... Ts>struct TuplePrinter<0, Ts...> { static void print(const tuple<Ts...>& t, ostream& out) { out << get<0>(t); } }; }
template<class... Ts>ostream& operator<<(ostream& out, const tuple<Ts...>& t) { out << "tuple("; if constexpr (sizeof...(Ts) > 0) { detail::TuplePrinter<sizeof...(Ts) - 1, Ts...>::print(t, out); } out << ")"; return out; }
template<class T>constexpr void read(T& X) { X = 0; int w = 0; char ch = 0; while (!isdigit(ch)) { w |= ch == '-'; ch = getchar(); }while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar(); if (w) X = -X; }
template<class T>constexpr void print(T x) { if (x < 0) putchar('-'), x = -x; if (x > 9) print(x / 10); putchar(x - x / 10 * 10 + '0'); }
template<typename T>constexpr T power(T a, u64 b) { T res{ 1 }; for (; b != 0; b /= 2, a *= a) { if (b % 2 == 1) { res *= a; } }return res; }
template<class T>constexpr T exgcd(T a, T b, T& x, T& y) { if (b == 0) { x = 1, y = 0; return a; }T g = exgcd(b, a % b, y, x); y -= a / b * x; return g; }
template<class T>constexpr T inverse(T a, T m) { T x, y; exgcd(a, m, x, y); return x; }
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };

//#define  QIO

#ifdef QIO
struct InputOutputStream {
    enum { SIZE = 1000001 };
    char ibuf[SIZE], * s, * t, obuf[SIZE], * oh;
    bool eof;
    InputOutputStream() : s(), t(), oh(obuf), eof(false) {}
    ~InputOutputStream() { fwrite(obuf, 1, oh - obuf, stdout); }
    explicit operator bool() const { return static_cast<bool>(eof == false); }
    inline char read() { if (s == t) t = (s = ibuf) + fread(ibuf, 1, SIZE, stdin); return s == t ? -1 : *s++; }
    inline InputOutputStream& operator>>(char* x) { static char c; for (c = read(); isspace(c); c = read()) if (c == -1) { eof = true; return *this; }for (; !isspace(c); c = read()) *x = c, ++x; *x = 0; return *this; }
    template <typename T>
    inline InputOutputStream& operator>>(T& x) { static char c; static bool iosig; for (c = read(), iosig = false; !isdigit(c); c = read()) { if (c == -1) { eof = true; return *this; }iosig |= c == '-'; }for (x = 0; isdigit(c); c = read()) x = x * 10 + (c ^ '0'); if (iosig) x = -x; return *this; }
    inline void print(char c) { if (oh == obuf + SIZE) { fwrite(obuf, 1, SIZE, stdout); oh = obuf; }  *oh++ = c; }
    template <typename T> inline void print(T x) { static int buf[23], cnt;  if (x != 0) { if (x < 0) print('-'), x = -x; for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 | 48; while (cnt) print((char)buf[cnt--]); } else print('0'); }
    template <typename T>inline InputOutputStream& operator<<(const T& x) { print(x);  return *this; }
    inline void print(const char* x) { for (; *x; x++)print(*x); }
    inline void print(char* x) { for (; *x; x++)   print(*x); }
} io;

#define endl '\n'
#define cin io
#define cout io
#endif 

//#define DMOD

#ifdef DMOD
constexpr i64 mul(i64 a, i64 b, i64 p) { i64 res = a * b - i64(1.L * a * b / p) * p; res %= p; if (res < 0) { res += p; }  return res; }
template<i64 P>
struct MLong {
    i64 x; constexpr MLong() : x{} {}
    constexpr MLong(i64 x) : x{ norm(x % getMod()) } {}
    static i64 Mod;    constexpr static i64 getMod() { if (P > 0) { return P; } else { return Mod; } }
    constexpr static void setMod(i64 Mod_) { Mod = Mod_; }  constexpr i64 norm(i64 x) const { if (x < 0) { x += getMod(); }if (x >= getMod()) { x -= getMod(); }return x; }
    constexpr i64 val() const { return x; }  explicit constexpr operator i64() const { return x; }
    constexpr MLong operator-() const { MLong res; res.x = norm(getMod() - x); return res; }
    constexpr MLong inv() const { assert(x != 0); return power(*this, getMod() - 2); }  constexpr MLong& operator*=(MLong rhs)& { x = mul(x, rhs.x, getMod()); return *this; }
    constexpr MLong& operator+=(MLong rhs)& { x = norm(x + rhs.x); return *this; }  constexpr MLong& operator-=(MLong rhs)& { x = norm(x - rhs.x); return *this; } constexpr MLong& operator/=(MLong rhs)& { return *this *= rhs.inv(); }
    friend constexpr MLong operator*(MLong lhs, MLong rhs) { MLong res = lhs; res *= rhs;  return res; }    friend constexpr MLong operator+(MLong lhs, MLong rhs) { MLong res = lhs;   res += rhs; return res; }
    friend constexpr MLong operator-(MLong lhs, MLong rhs) { MLong res = lhs;  res -= rhs; return res; }    friend constexpr MLong operator/(MLong lhs, MLong rhs) { MLong res = lhs; res /= rhs; return res; }
    friend constexpr std::istream& operator>>(std::istream& is, MLong& a) { i64 v;  is >> v;  a = MLong(v); return is; }   friend constexpr std::ostream& operator<<(std::ostream& os, const MLong& a) { return os << a.val(); }
    friend constexpr bool operator==(MLong lhs, MLong rhs) { return lhs.val() == rhs.val(); }    friend constexpr bool operator!=(MLong lhs, MLong rhs) { return lhs.val() != rhs.val(); }
};
template<>
i64 MLong<0LL>::Mod = i64(1E18) + 9;
template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{ norm(x % getMod()) } {}
    static int Mod;
    constexpr static int getMod() { if (P > 0) { return P; } else { return Mod; } }
    constexpr static void setMod(int Mod_) { Mod = Mod_; }    constexpr int norm(int x) const { if (x < 0) { x += getMod(); }  if (x >= getMod()) { x -= getMod(); } return x; }
    constexpr int val() const { return x; }   explicit constexpr operator int() const { return x; }
    constexpr MInt operator-() const { MInt res;  res.x = norm(getMod() - x); return res; }    constexpr MInt inv() const { assert(x != 0);  return power(*this, getMod() - 2); }
    constexpr MInt& operator*=(MInt rhs)& { x = 1LL * x * rhs.x % getMod(); return *this; } constexpr MInt& operator+=(MInt rhs)& { x = norm(x + rhs.x);  return *this; }
    constexpr MInt& operator-=(MInt rhs)& { x = norm(x - rhs.x); return *this; } constexpr MInt& operator/=(MInt rhs)& { return *this *= rhs.inv(); }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) { MInt res = lhs;    res *= rhs;   return res; }   friend constexpr MInt operator+(MInt lhs, MInt rhs) { MInt res = lhs;  res += rhs;  return res; }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) { MInt res = lhs; res -= rhs; return res; } friend constexpr MInt operator/(MInt lhs, MInt rhs) { MInt res = lhs; res /= rhs; return res; }
    friend constexpr std::istream& operator>>(std::istream& is, MInt& a) { i64 v; is >> v; a = MInt(v); return is; } friend constexpr std::ostream& operator<<(std::ostream& os, const MInt& a) { return os << a.val(); }
    friend constexpr bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }  friend constexpr bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
};
template<>
int MInt<0>::Mod = 998244353;
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();
constexpr int mod = 1000000007;
using Z = MInt<0>;
#endif
#ifndef DMOD
template<u32 P>constexpr u32 mulMod(u32 a, u32 b) { return 1ULL * a * b % P; }
template<u64 P>constexpr u64 mulMod(u64 a, u64 b) { u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P; res %= P; return res; }
template<typename U, U P> requires std::unsigned_integral<U>
struct ModIntBase {
public:constexpr ModIntBase() : x{ 0 } {}
      template<typename T>requires std::integral<T> constexpr ModIntBase(T x_) : x{ norm(x_ % T {P}) } {}
      constexpr static U norm(U x) { if ((x >> (8 * sizeof(U) - 1) & 1) == 1) { x += P; }if (x >= P) { x -= P; }return x; }
      constexpr U val() const { return x; }constexpr ModIntBase operator-() const { ModIntBase res; res.x = norm(P - x); return res; }constexpr ModIntBase inv() const { return power(*this, P - 2); }
      constexpr ModIntBase& operator*=(const ModIntBase& rhs)& { x = mulMod<P>(x, rhs.val()); return *this; }
      constexpr ModIntBase& operator+=(const ModIntBase& rhs)& { x = norm(x + rhs.x); return *this; }
      constexpr ModIntBase& operator-=(const ModIntBase& rhs)& { x = norm(x - rhs.x); return *this; }constexpr ModIntBase& operator/=(const ModIntBase& rhs)& { return *this *= rhs.inv(); }
      friend constexpr ModIntBase operator*(ModIntBase lhs, const ModIntBase& rhs) { lhs *= rhs; return lhs; }
      friend constexpr ModIntBase operator+(ModIntBase lhs, const ModIntBase& rhs) { lhs += rhs; return lhs; }
      friend constexpr ModIntBase operator-(ModIntBase lhs, const ModIntBase& rhs) { lhs -= rhs; return lhs; }friend constexpr ModIntBase operator/(ModIntBase lhs, const ModIntBase& rhs) { lhs /= rhs; return lhs; }
      friend constexpr std::ostream& operator<<(std::ostream& os, const ModIntBase& a) { return os << a.val(); }
      friend constexpr bool operator==(ModIntBase lhs, ModIntBase rhs) { return lhs.val() == rhs.val(); }
      friend constexpr bool operator!=(ModIntBase lhs, ModIntBase rhs) { return lhs.val() != rhs.val(); }
      friend constexpr bool operator<(ModIntBase lhs, ModIntBase rhs) { return lhs.val() < rhs.val(); }
private: U x;
};
template<u32 P> using ModInt = ModIntBase<u32, P>;
template<u64 P> using ModInt64 = ModIntBase<u64, P>;
constexpr u32 mod = 1e9 + 7;

using Z = ModInt<mod>;
#endif
const ll N = 1e5 + 5, inf = 1e18, M = 5e5 + 5;
const ld eps = 1e-12;


template<class Info>
struct SegmentTree {
#define mid ((l+r)/2)
    int n;
    std::vector<Info> node;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size() - 1;
        node.assign(4 << (int)log2(n + 1), Info());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r == l)return void(node[p] = init_[l]);
            build(2 * p, l, mid);
            build(2 * p + 1, mid + 1, r);
            pushup(p);
            };
        build(1, 0, n);
    }
    void pushup(int p) {
        node[p] = node[2 * p] + node[2 * p + 1];
    }
    void update(int p, int l, int r, int x, const Info& v) {
        if (r == l)return void(node[p] = v);
        if (x <= mid) update(2 * p, l, mid, x, v);
        else update(2 * p + 1, mid + 1, r, x, v);
        pushup(p);
    }
    void update(int p, const Info& v) {
        update(1, 0, n, p, v);
    }
    Info query(int p, int l, int r, int x, int y) {
        if (l >= x && r <= y)
            return node[p];
        if (y <= mid)
            return query(2 * p, l, mid, x, y);
        if (x > mid)
            return query(2 * p + 1, mid + 1, r, x, y);
        return query(2 * p, l, mid, x, y) + query(2 * p + 1, mid + 1, r, x, y);
    }
    Info query(int l, int r) {
        return query(1, 0, n, l, r);
    }
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F pred) {
        if (l > y || r < x || !pred(node[p]))return -1;
        if (r == l)return l;
        int res = findFirst(2 * p, l, mid, x, y, pred);
        if (res == -1)res = findFirst(2 * p + 1, mid + 1, r, x, y, pred);
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F pred) {
        if (l > y || r < x || !pred(node[p]))return -1;
        if (r == l)return l;
        int res = findLast(2 * p + 1, mid + 1, r, x, y, pred);
        if (res == -1) res = findLast(2 * p, l, mid, x, y, pred);
        return res;
    }
    template<class F>
    int findLast(int l, int r, F pred) {
        return findLast(1, 0, n, l, r, pred);
    }
#undef mid
};

const ll mod1 = 1610612741, base1 = 114514;

const ll mod2 = 1004535809, base2 = 54321;

ll pow1[N], pow2[N];

struct Info {
    ll x1 = 0, rx1 = 0;
    ll x2 = 0, rx2 = 0;
    int siz = 0;
};

Info operator+(Info a, Info b) {
    Info c;
    c.siz = a.siz + b.siz;
    c.x1 = (a.x1 * pow1[b.siz] + b.x1) % mod1;
    c.x2 = (a.x2 * pow2[b.siz] + b.x2) % mod2;
    c.rx1 = (b.rx1 * pow1[a.siz] + a.rx1) % mod1;
    c.rx2 = (b.rx2 * pow2[a.siz] + a.rx2) % mod2;
    return c;
}


struct HLD {
    int n;
    vector<int> siz, top, dep, parent, in, out, seq;
    vector<vector<int>> e;
    int cur;

    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n + 1);
        top.resize(n + 1);
        dep.resize(n + 1);
        parent.resize(n + 1);
        in.resize(n + 1);
        out.resize(n + 1);
        seq.resize(n + 1);
        cur = 0;
        e.assign(n + 1, {});
    }
    void addEdge(int u, int v) {
        e[u].push_back(v);
        e[v].push_back(u);
    }
    void work(int root = 1) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            e[u].erase(std::find(e[u].begin(), e[u].end(), parent[u]));
        }

        siz[u] = 1;
        for (auto& v : e[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[e[u][0]]) {
                swap(v, e[u][0]);
            }
        }
    }
    void dfs2(int u) {
        in[u] = ++cur;
        seq[in[u]] = u;
        for (auto v : e[u]) {
            top[v] = v == e[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            }
            else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }

    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    int jump(int u, int k) {
        if (dep[u] < k) {
            return -1;
        }

        int d = dep[u] - k;

        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }

        return seq[in[u] - dep[u] + d];
    }
    // u是否是v的祖先
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }
    // 确定在以 u 为根的树中，节点 v 的父节点。
    int rootedParent(int u, int v) {
        std::swap(u, v);
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return parent[u];
        }
        auto it = upper_bound(e[u].begin(), e[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
            }) - 1;
        return *it;
    }
    // 以 u 为根的树中，节点 v 的子树大小。
    int rootedSize(int u, int v) {
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }

    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }

    auto getPath(int u, int v) {
        vector<pair<int, int>> ret;
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                ret.push_back({ in[top[u]], in[u] });
                u = parent[top[u]];
            }
            else {
                ret.push_back({ in[top[v]], in[v] });
                v = parent[top[v]];
            }
        }
        if (dep[u] > dep[v])  swap(u, v);
        ret.push_back({ in[u] + 1, in[v] });
        return ret;
    }
    template<class Tag>
    void modify(int l, int r, const Tag& v);

    template<class Tag>
    void modify(int root, const Tag& v);

    template<class Info>
    Info query(int l, int r);

    template<class Info>
    Info query(int root);
};
SegmentTree<Info> seg;

Info reverseInfo(const Info& a) {
    Info b;
    b.siz = a.siz;
    b.x1 = a.rx1;
    b.x2 = a.rx2;
    b.rx1 = a.x1;
    b.rx2 = a.x2;
    return b;
}


template<class Info>
Info HLD::query(int u, int v) {
    int L = lca(u, v);
    Info up;
    Info down;

    while (top[u] != top[L]) {
        Info seg_part = seg.query(in[top[u]], in[u]);
        up = up + reverseInfo(seg_part);
        u = parent[top[u]];
    }
    if (u != L) {
        Info seg_part = seg.query(in[L] + 1, in[u]);
        up = up + reverseInfo(seg_part);
    }

    while (top[v] != top[L]) {
        Info seg_part = seg.query(in[top[v]], in[v]);
        down = seg_part + down;
        v = parent[top[v]];
    }
    if (v != L) {
        Info seg_part = seg.query(in[L] + 1, in[v]);
        down = seg_part + down;
    }
    return up + down;
}

void solve() {
    int n, q;
    cin >> n >> q;
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < N; i++) {
        pow1[i] = pow1[i - 1] * base1 % mod1;
        pow2[i] = pow2[i - 1] * base2 % mod2;
    }

    HLD tr(n);
    vector<array<int, 3>> e(n);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        char w;
        cin >> u >> v >> w;
        tr.addEdge(u, v);
        e[i] = { u, v, w };
    }

    vector<Info> init(n + 1, Info());

    tr.work(1);

    seg.init(n + 1);
    for (int i = 1; i <= n; i++) {
        init[i].x1 = init[i].x2 = 0;
        init[i].siz = 0;
    }

    for (int i = 1; i <= n - 1; i++) {
        auto [u, v, w] = e[i];
        int x = u;
        if (tr.dep[u] < tr.dep[v]) x = v;

        int val = w - 'a' + 1;
        init[tr.in[x]].x1 = init[tr.in[x]].x2 = init[tr.in[x]].rx1 = init[tr.in[x]].rx2 = val;
        init[tr.in[x]].siz = 1;
    }

    seg.init(init);

    map<pair<ll, ll>, int> mp;
    int res = 0;
    while (q--) {
        int u, v;
        cin >> u >> v;
        Info ans = tr.query<Info>(u, v);
        pair<ll, ll> key = { ans.x1, ans.x2 };
        if (!mp.count(key)) {
            res++;
        }
        mp[key] = 1;
        cout << res << endl;
    }
}

signed main() {
#ifndef QIO
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#endif
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}