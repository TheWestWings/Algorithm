#pragma GCC optimiaze("O3")
#pragma GCC optimiez("Ofast")
 
#include <bits/stdc++.h>
#define int long long
//#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;
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
template<class T> constexpr T power(T a, u64 b, ll m) { ll res = 1; while (b) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; }return res; }
struct pair_hash { template <class T1, class T2>std::size_t operator() (const std::pair<T1, T2>& pair) const { return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second); } };
template<typename T> ostream& operator << (ostream& out, const set<T>& obj) { out << "set("; for (auto it = obj.begin(); it != obj.end(); it++) out << (it == obj.begin() ? "" : ", ") << *it; out << ")"; return out; }
template<typename T1, typename T2> ostream& operator << (ostream& out, const map<T1, T2>& obj) { out << "map("; for (auto it = obj.begin(); it != obj.end(); it++) out << (it == obj.begin() ? "" : ", ") << it->first << ": " << it->second; out << ")"; return out; }
template<typename T1, typename T2> ostream& operator << (ostream& out, const pair<T1, T2>& obj) { out << "<" << obj.first << ", " << obj.second << ">"; return out; }
template<typename T> ostream& operator << (ostream& out, const vector<T>& obj) { out << "vector("; for (auto it = obj.begin(); it != obj.end(); it++) out << (it == obj.begin() ? "" : ", ") << *it; out << ")"; return out; }
template<class T>constexpr void read(T& X) { X = 0; int w = 0; char ch = 0; while (!isdigit(ch)) { w |= ch == '-'; ch = getchar(); }while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar(); if (w) X = -X; }
template<class T>constexpr void print(T x) { if (x < 0) putchar('-'), x = -x; if (x > 9) print(x / 10); putchar(x - x / 10 * 10 + '0'); }
template<typename T>constexpr T power(T a, u64 b) { T res{ 1 }; for (; b != 0; b /= 2, a *= a) { if (b % 2 == 1) { res *= a; } }return res; }
template<class T>constexpr T exgcd(T a, T b, T& x, T& y) { if (b == 0) { x = 1, y = 0; return a; }T g = exgcd(b, a % b, y, x); y -= a / b * x; return g; }
template<class T>constexpr T inverse(T a, T m) { T x, y; exgcd(a, m, x, y); return x; }
template<u32 P>constexpr u32 mulMod(u32 a, u32 b) { return 1ULL * a * b % P; }
template<u64 P>constexpr u64 mulMod(u64 a, u64 b) { u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P; res %= P; return res; }

void solve(){
    int n;
    cin >> n;

    vector<int> s1(n + 1), s2(n + 1);
    vector<vector<int>> a(2, vector<int>(n + 1));
    for(int i = 0; i < 2; i ++){
        for(int j = 1; j <= n; j ++){
            cin >> a[i][j];
        }
    }
    // cout << a[0]   << endl;
    for(int i = 1; i <= n; i ++){
        s1[i] = s1[i - 1] + a[0][i];
    }
    for(int i = n; i >= 1; i --){
        s2[i] = s2[i + 1] + a[1][i];
    }
    // cout << s1 << endl;
    // cout << s2 << endl;

    int mx = -1e18, mxi = -1;
    for(int i = 1; i <= n; i ++){
        // cout << s1[i] + s2[i] << endl;
        if(s1[i] + s2[i] > mx){
            mx = s1[i] + s2[i];
            mxi = i;
        }
    }
    // cout << mx << " " << mxi << endl;

    vector<int> mx1(n + 2, -1e18), mx2(n + 2, -1e18);
    for(int i = 1; i < mxi; i ++){
        // cout << -a[0][i] + a[1][i] << endl;
        mx1[i] = max(mx1[i - 1], -a[0][i] + a[1][i]);
    }
    for(int i = mxi + 1; i <= n; i ++){
        // cout << a[0][i] - a[1][i] << endl;
        mx2[i] = max(mx2[i + 1], a[0][i] - a[1][i]);
    }
    // cout << mx1 << " " << mx2 << endl;
    int ans = mx;
    ans = max(ans, mx + (mx1 + mx2));
    
    int t = mx;
    int tmp = -1e18;
    for(int i = 1; i <= n; i ++){
        if(i == mxi) continue;
        if(i < mxi){
            tmp = max(tmp, (-a[1][mxi] + a[1][i]));
            // t = max(t, mx - a[1][mxi] + a[1][i]);
        }
        else{
            // t = max(t, mx - a[0][mxi] + a[0][i]);
            tmp = max(tmp, (a[0][i] - a[0][mxi]));
        }
    }
    t = max(t, mx + tmp);
    cout << max(ans, t) << endl;
    
    
}

signed main(){
    int t = 1;
    cin >> t;

    while(t --){
        solve();
    }
}