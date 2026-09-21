/*
Copyright (C) 2026 TangYixiao
*/
#define PRAGMA_TYPE 0                     // 0 for no pragma, 1 for O3, 2 for extended optimize, 3 for compiler options
#define PRAGMA_GCC_or_GPlusPlus_ALLOWED 0 // 0 for disabled, 1 for GCC
#define JUDGE_TYPE 0                      // 0 for online judge, 1 for judge file, 2 for local file
#define FILE_INDEX 1                      // the index of the file in the local file system
// #define MULTIPLE_TEST
// #define DEBUG
// #define TIME_COUNT
#define FILE_NAME ""
// #define BITS_NOT_ALLOWED
// #define PD_DS_USED
// #define TESTLIB
// clang-format off
#pragma region PREPROCESSOR
#pragma region PRAGMAS
#if PRAGMA_TYPE == 1
#pragma GCC optimize("O3")
#elif PRAGMA_TYPE == 2
#if PRAGMA_GCC_or_GPlusPlus_ALLOWED == 1
#pragma GCC optimize("O3","unroll-loops","inline-functions","no-stack-protector")
#endif
#elif PRAGMA_TYPE == 3
// Put compiler-specific pragmas here when a problem really needs them.
#endif
#pragma endregion PRAGMAS
#pragma region INCLUDES
#ifdef TESTLIB
#include <testlib.h>
#endif
#ifdef BITS_NOT_ALLOWED
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
#ifdef PD_DS_USED
#ifdef BITS_NOT_ALLOWED
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/exception.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/list_update_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>
#else
#include <bits/extc++.h>
#endif
namespace pbds = __gnu_pbds;
#endif
#ifdef __linux__
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#endif
using namespace std;
#pragma endregion INCLUDES
#pragma region TANGYIXIAO
namespace TANGYIXIAO {
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#ifdef __SIZEOF_INT128__
using i128 = __int128_t;
using u128 = __uint128_t;
#endif
template<class T>
struct Unsigned_Of { using type = typename make_unsigned<T>::type; };
#ifdef __SIZEOF_INT128__
template<> struct Unsigned_Of<i128> { using type = u128; };
template<> struct Unsigned_Of<u128> { using type = u128; };
#endif
template<class T> inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
#pragma region IO
#ifdef __SIZEOF_INT128__
inline istream &operator>>(istream &is, i128 &x) { string s; is >> s; int p = 0, neg = 0; if (!s.empty() && s[0] == '-') { neg = 1; p = 1; } u128 v = 0; for (; p < (int)s.size(); p++) { v = (v << 3) + (v << 1) + (unsigned)(s[p] - '0'); } if (neg) { x = -i128(v - 1) - 1; } else { x = i128(v); } return is; }
inline istream &operator>>(istream &is, u128 &x) { string s; is >> s; int p = !s.empty() && s[0] == '+'; x = 0; for (; p < (int)s.size(); p++) { x = (x << 3) + (x << 1) + (unsigned)(s[p] - '0'); } return is; }
inline ostream &operator<<(ostream &os, i128 x) { if (x == 0) { os << '0'; return os; } u128 v; if (x < 0) { os << '-', v = u128(-(x + 1)) + 1; } else { v = u128(x); } char s[64]; int n = 0; for (; v; v /= 10) { s[n++] = char('0' + v % 10); } for (int i = n - 1; i >= 0; i--) { os << s[i]; } return os; }
inline ostream &operator<<(ostream &os, u128 x) { if (x == 0) { os << '0'; return os; } char s[64]; int n = 0; for (; x; x /= 10) { s[n++] = char('0' + x % 10); } for (int i = n - 1; i >= 0; i--) { os << s[i]; } return os; }
#endif
namespace IO {
#pragma region FAST_IO
namespace FAST_IO {
inline void IOSS_Init() { ios::sync_with_stdio(false), cin.tie(nullptr); return; }
} // namespace FAST_IO
using namespace FAST_IO;
#pragma endregion FAST_IO
#pragma region FILE_IO
namespace FILE_IO {
const string Insuffix = ".in", Outsuffix = ".out", Anssuffix = ".ans";
inline void Judge_File(const string &name) { freopen((name + Insuffix).c_str(), "r", stdin), freopen((name + Outsuffix).c_str(), "w", stdout); return; }
inline void Local_File(const string &name, int idx) { freopen((name + to_string(idx) + Insuffix).c_str(), "r", stdin), freopen((name + to_string(idx) + Outsuffix).c_str(), "w", stdout); return; }
} // namespace FILE_IO
using namespace FILE_IO;
#pragma endregion FILE_IO
template<class T>
inline bool read_getchar(T &x) { typedef typename Unsigned_Of<T>::type U; int c = getchar(); bool neg = false; U v = 0; for (; c != EOF && c <= ' '; c = getchar()) {} if (c == EOF) { return false; } if (c == '-') { neg = true, c = getchar(); } for (; c >= '0' && c <= '9'; c = getchar()) { v = (v << 3) + (v << 1) + U(c - '0'); } x = neg && v ? T(-T(v - 1) - 1) : T(v); return true; }
#if defined(_WIN32)
inline int unlocked_getchar() { return _getchar_nolock(); }
inline int unlocked_putchar(int c) { return _putchar_nolock(c); }
#else
inline int unlocked_getchar() { return getchar_unlocked(); }
inline int unlocked_putchar(int c) { return putchar_unlocked(c); }
#endif
template<class T>
inline bool read_unlocked(T &x) { typedef typename Unsigned_Of<T>::type U; int c = unlocked_getchar(); bool neg = false; U v = 0; for (; c != EOF && c <= ' '; c = unlocked_getchar()) {} if (c == EOF) { return false; } if (c == '-') { neg = true, c = unlocked_getchar(); } for (; c >= '0' && c <= '9'; c = unlocked_getchar()) { v = (v << 3) + (v << 1) + U(c - '0'); } x = neg && v ? T(-T(v - 1) - 1) : T(v); return true; }
struct Fread_Input {
    static const int S = 1 << 20;
    int p = 0, n = 0; char b[S];
    inline int gc() { if (p == n) { n = (int)fread(b, 1, S, stdin), p = 0; if (!n) { return EOF; } } return b[p++]; }
    template<class T>
    inline bool read_int(T &x) { typedef typename Unsigned_Of<T>::type U; int c = gc(); bool neg = false; U v = 0; for (; c != EOF && c <= ' '; c = gc()) {} if (c == EOF) { return false; } if (c == '-') { neg = true, c = gc(); } for (; c >= '0' && c <= '9'; c = gc()) { v = (v << 3) + (v << 1) + U(c - '0'); } x = neg && v ? T(-T(v - 1) - 1) : T(v); return true; }
    inline bool read_char(char &c) { int x = gc(); for (; x != EOF && x <= ' '; x = gc()) {} if (x == EOF) { return false; } c = (char)x; return true; }
    inline bool read_string(string &s) { int c = gc(); for (; c != EOF && c <= ' '; c = gc()) {} if (c == EOF) { return false; } s.clear(); for (; c != EOF && c > ' '; c = gc()) { s.push_back((char)c); } return true; }
    template<class T>
    inline bool read_float(T &x) { string s; if (!read_string(s)) { return false; } x = (T)strtold(s.c_str(), nullptr); return true; }
};
struct Fwrite_Output {
    static const int S = 1 << 20;
    int p = 0; char b[S];
    inline ~Fwrite_Output() { flush(); }
    inline void flush() { if (p) { fwrite(b, 1, p, stdout), p = 0; } return; }
    inline void pc(char c) { if (p == S) { flush(); } b[p++] = c; return; }
    template<class T>
    inline void write_int(T x, char end = 0) { typedef typename Unsigned_Of<T>::type U; bool neg = x < 0; U v = neg ? U(-(x + 1)) + 1 : U(x); if (neg) { pc('-'); } if (!v) { pc('0'); } else { char s[64]; int n = 0; for (; v; v /= 10) { s[n++] = char('0' + v % 10); } for (int i = n - 1; i >= 0; i--) { pc(s[i]); } } if (end) { pc(end); } return; }
    inline void write_char(char c) { pc(c); return; }
    inline void write_string(const string &s, char end = 0) { for (char c : s) { pc(c); } if (end) { pc(end); } return; }
    inline void write_cstr(const char *s, char end = 0) { for (; *s; s++) { pc(*s); } if (end) { pc(end); } return; }
    template<class T>
    inline void write_float(T x, int precision = 10, char end = 0) { char s[128]; int n = snprintf(s, sizeof(s), "%.*Lf", precision, (long double)x); for (int i = 0; i < n; i++) { pc(s[i]); } if (end) { pc(end); } return; }
};
#ifdef __linux__
// Optional Linux-only input. Do not enable where mmap is forbidden by contest rules.
struct MMap_Input {
    const char *p = nullptr, *e = nullptr; void *base = MAP_FAILED; size_t len = 0;
    inline MMap_Input() { struct stat st; if (fstat(STDIN_FILENO, &st) == 0 && S_ISREG(st.st_mode) && st.st_size > 0) { len = (size_t)st.st_size, base = mmap(nullptr, len, PROT_READ, MAP_PRIVATE, STDIN_FILENO, 0); if (base != MAP_FAILED) { p = (const char *)base, e = p + len; } } }
    inline ~MMap_Input() { if (base != MAP_FAILED) { munmap(base, len); } }
    template<class T>
    inline bool read_int(T &x) { typedef typename Unsigned_Of<T>::type U; if (!p) { return false; } bool neg = false; U v = 0; for (; p < e && *p <= ' '; p++) {} if (p == e) { return false; } if (*p == '-') { neg = true, p++; } for (; p < e && *p >= '0' && *p <= '9'; p++) { v = (v << 3) + (v << 1) + U(*p - '0'); } x = neg && v ? T(-T(v - 1) - 1) : T(v); return true; }
};
#endif
} // namespace IO
using namespace IO;
#pragma endregion IO
#pragma region TIME
namespace TIME {
clock_t Start_Time, End_Time;
inline void Start_Time_Count() { Start_Time = clock(); return; }
inline void End_Time_Count() { End_Time = clock(); return; }
inline double Time_Count() { return (double)(End_Time - Start_Time) / CLOCKS_PER_SEC; }
inline void Print_Time_Count(const string &name) { cerr << fixed << setprecision(4) << "\n" << name << " Time: " << Time_Count() << "s\n"; return; }
} // namespace TIME
using namespace TIME;
#pragma endregion TIME
#pragma region DEBUGS
namespace DEBUGS {
#define All(x) (x).begin(), (x).end()
inline void Debug_Print(const string &s) { cerr << "\n" << s << "\n"; return; }
} // namespace DEBUGS
using namespace DEBUGS;
#pragma endregion DEBUGS
#pragma region RANDOM
namespace RANDOM {
inline mt19937_64 &engine() { static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() ^ (ull)(uintptr_t)new char); return rng; }
inline ull next_u64() { return engine()(); }
inline ll range(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(engine()); }
} // namespace RANDOM
#pragma endregion
#pragma region BITS
namespace BITS {
template<class T> inline T lowbit(T x) { typedef typename Unsigned_Of<T>::type U; U v = (U)x; return (T)(v & (U(0) - v)); }
inline int bit_count(unsigned int x) { return __builtin_popcount(x); }
inline int bit_count(unsigned long x) { return __builtin_popcountl(x); }
inline int bit_count(unsigned long long x) { return __builtin_popcountll(x); }
inline int bit_count(int x) { return __builtin_popcount((unsigned)x); }
inline int bit_count(long x) { return __builtin_popcountl((unsigned long)x); }
inline int bit_count(long long x) { return __builtin_popcountll((unsigned long long)x); }
#ifdef __SIZEOF_INT128__
inline int bit_count(u128 x) { return __builtin_popcountll((ull)x) + __builtin_popcountll((ull)(x >> 64)); }
inline int bit_count(i128 x) { return bit_count((u128)x); }
#endif
inline int leading_zero_count(unsigned int x) { return x ? __builtin_clz(x) : 32; }
inline int leading_zero_count(unsigned long long x) { return x ? __builtin_clzll(x) : 64; }
inline int trailing_zero_count(unsigned int x) { return x ? __builtin_ctz(x) : 32; }
inline int trailing_zero_count(unsigned long long x) { return x ? __builtin_ctzll(x) : 64; }
inline int bit_length(unsigned int x) { return x ? 32 - __builtin_clz(x) : 0; }
inline int bit_length(unsigned long long x) { return x ? 64 - __builtin_clzll(x) : 0; }
#ifdef __SIZEOF_INT128__
inline int bit_length(u128 x) { ull h = (ull)(x >> 64); return h ? 64 + bit_length(h) : bit_length((ull)x); }
#endif
template<class T> inline bool is_power_of_two(T x) { return x > 0 && !(x & (x - 1)); }
template<class T> inline T floor_power_of_two(T x) { if (x <= 0) { return 0; } typedef typename Unsigned_Of<T>::type U; U v = (U)x, r = 1, nr; for (; (nr = r << 1) && nr <= v; r = nr) {} return (T)r; }
template<class T> inline T ceil_power_of_two(T x) { if (x <= 1) { return 1; } typedef typename Unsigned_Of<T>::type U; U v = (U)x, r = 1, nr; for (; r < v; r = nr) { nr = r << 1; if (!nr || (is_signed<T>::value && nr > (U)numeric_limits<T>::max())) { return 0; } } return (T)r; }
template<class T> inline T gray_code(T x) { return x ^ (x >> 1); }
} // namespace BITS
using namespace BITS;
#pragma endregion
#pragma region MATH
namespace MATH {
template<class T, class U>
inline T qpow(T a, U b) { T r = 1; for (; b; b >>= 1, a = a * a) { if (b & 1) { r = r * a; } } return r; }
inline ull qmul(ull a, ull b, ull mod) {
#ifdef __SIZEOF_INT128__
    return (ull)((u128)a * b % mod);
#else
    ull r = 0; for (; b; b >>= 1, a = (a + a) % mod) { if (b & 1) { r = (r + a) % mod; } } return r;
#endif
}
inline ull qpow(ull a, ull b, ull mod) { ull r = 1 % mod; for (a %= mod; b; b >>= 1, a = qmul(a, a, mod)) { if (b & 1) { r = qmul(r, a, mod); } } return r; }
template<class T>
inline T gcd(T a, T b) { if (a < 0) { a = -a; } if (b < 0) { b = -b; } for (; b;) { T t = a % b; a = b, b = t; } return a; }
template<class T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T>
inline T exgcd(T a, T b, T &x, T &y) { if (!b) { x = 1, y = 0; return a; } T x1, y1, g = exgcd(b, a % b, x1, y1); x = y1, y = x1 - a / b * y1; return g; }
template<class T>
inline T inv(T a, T mod) { T x, y, g = exgcd(a, mod, x, y); if (g < 0) { g = -g, x = -x; } if (g != 1) { return 0; } x %= mod; if (x < 0) { x += mod; } return x; }
inline pair<ll, ll> crt_merge(ll r1, ll m1, ll r2, ll m2) { ll x, y, g = exgcd(m1, m2, x, y), d = r2 - r1; if (d % g) { return {0, -1}; } ll mod = m2 / g;
#ifdef __SIZEOF_INT128__
    ll t = (ll)((i128)(d / g) * x % mod); if (t < 0) { t += mod; } i128 l = (i128)m1 / g * m2, r = (i128)r1 + (i128)m1 * t; r %= l; if (r < 0) { r += l; } if (l > LLONG_MAX) { return {0, -2}; } return {(ll)r, (ll)l};
#else
    ll t = (d / g * x) % mod; if (t < 0) { t += mod; } ll l = m1 / g * m2, r = (r1 + m1 * t) % l; if (r < 0) { r += l; } return {r, l};
#endif
}
inline bool Miller_Rabin(ull n) { if (n < 2) { return false; } for (ull p : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL}) { if (n % p == 0) { return n == p; } } ull d = n - 1, s = 0; for (; !(d & 1); d >>= 1) { s++; }
    for (ull a : {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL}) { if (a % n == 0) { continue; } ull x = qpow(a % n, d, n); if (x == 1 || x == n - 1) { continue; } bool ok = false; for (ull r = 1; r < s; r++) { x = qmul(x, x, n); if (x == n - 1) { ok = true; break; } } if (!ok) { return false; } } return true;
}
inline ull Pollard_Rho(ull n) { if (!(n & 1)) { return 2; } if (n % 3 == 0) { return 3; } for (;;) { ull c = RANDOM::next_u64() % (n - 1) + 1, x = RANDOM::next_u64() % n, y = x, d = 1; auto f = [&](ull v) -> ull { return (qmul(v, v, n) + c) % n; }; for (; d == 1;) { x = f(x), y = f(f(y)); ull z = x > y ? x - y : y - x; d = gcd(z, n); } if (d != n) { return d; } } }
inline void factor(ull n, vector<ull> &v) { if (n == 1) { return; } if (Miller_Rabin(n)) { v.push_back(n); return; } ull d = Pollard_Rho(n); factor(d, v), factor(n / d, v); return; }
} // namespace MATH
using MATH::qpow; using MATH::qmul; using MATH::exgcd; using MATH::inv;
#pragma endregion
#pragma region BIG_INTEGER
namespace BIG_INTEGER_DETAIL {
template<int MOD, int ROOT>
struct NTT {
    static inline int mod_pow(long long a, long long b) { long long r = 1; for (; b; b >>= 1, a = a * a % MOD) { if (b & 1) { r = r * a % MOD; } } return (int)r; }
    static inline void transform(vector<int> &a, bool invert) { int n = (int)a.size();
        for (int i = 1, j = 0; i < n; i++) { int bit = n >> 1; for (; j & bit; bit >>= 1) { j ^= bit; } j ^= bit; if (i < j) { swap(a[i], a[j]); } }
        for (int len = 2; len <= n; len <<= 1) { int wlen = mod_pow(ROOT, (MOD - 1) / len); if (invert) { wlen = mod_pow(wlen, MOD - 2); } for (int i = 0; i < n; i += len) { ll w = 1; for (int j = 0; j < len / 2; j++) { int u = a[i + j], v = (int)(a[i + j + len / 2] * w % MOD), x = u + v, y = u - v; if (x >= MOD) { x -= MOD; } if (y < 0) { y += MOD; } a[i + j] = x, a[i + j + len / 2] = y, w = w * wlen % MOD; } } }
        if (invert) { int inv_n = mod_pow(n, MOD - 2); for (int &x : a) { x = (int)((ll)x * inv_n % MOD); } } return;
    }
    static inline vector<int> convolution(const vector<int> &a, const vector<int> &b) { if (a.empty() || b.empty()) { return {}; } int n = 1; for (; n < (int)a.size() + (int)b.size() - 1; n <<= 1) {} vector<int> x(n), y(n); for (int i = 0; i < (int)a.size(); i++) { x[i] = a[i] % MOD; } for (int i = 0; i < (int)b.size(); i++) { y[i] = b[i] % MOD; }
        transform(x, false), transform(y, false); for (int i = 0; i < n; i++) { x[i] = (int)((ll)x[i] * y[i] % MOD); } transform(x, true), x.resize(a.size() + b.size() - 1); return x;
    }
};
inline vector<ll> convolution_ntt_crt(const vector<int> &a, const vector<int> &b) { static const ll P1 = 998244353LL, P2 = 1004535809LL, INV = []() -> ll { ll x, y; MATH::exgcd(P1, P2, x, y), x %= P2; if (x < 0) { x += P2; } return x; }(); vector<int> x = NTT<998244353, 3>::convolution(a, b), y = NTT<1004535809, 3>::convolution(a, b); vector<ll> r(x.size());
    for (int i = 0; i < (int)x.size(); i++) { ll t = (y[i] - (ll)x[i]) % P2; if (t < 0) { t += P2; } t = t * INV % P2, r[i] = x[i] + P1 * t; } return r;
}
inline vector<ll> karatsuba_rec(const vector<ll> &a, const vector<ll> &b) { int n = (int)a.size(); vector<ll> r(n + n); if (n <= 32) { for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { r[i + j] += a[i] * b[j]; } } return r; } int k = n >> 1; vector<ll> a1(a.begin(), a.begin() + k), a2(a.begin() + k, a.end()), b1(b.begin(), b.begin() + k), b2(b.begin() + k, b.end()), a12(k), b12(k);
    for (int i = 0; i < k; i++) { a12[i] = a1[i] + a2[i], b12[i] = b1[i] + b2[i]; } vector<ll> x = karatsuba_rec(a1, b1), y = karatsuba_rec(a2, b2), z = karatsuba_rec(a12, b12); for (int i = 0; i < (int)x.size(); i++) { z[i] -= x[i] + y[i], r[i] += x[i]; } for (int i = 0; i < (int)z.size(); i++) { r[i + k] += z[i]; } for (int i = 0; i < (int)y.size(); i++) { r[i + k + k] += y[i]; } return r;
}
inline vector<long long> convolution_karatsuba(vector<int> a, vector<int> b) { int need = (int)a.size() + (int)b.size() - 1; int n = 1; for (; n < (int)max(a.size(), b.size()); n <<= 1) {} a.resize(n); b.resize(n); vector<long long> x(n), y(n); for (int i = 0; i < n; i++) { x[i] = a[i]; y[i] = b[i]; } vector<long long> r = karatsuba_rec(x, y); r.resize(need); return r; }
} // namespace BIG_INTEGER_DETAIL
struct BigInt {
    static const int base = 1000000000;
    static const int base_digits = 9;
    vector<int> a;
    int sign = 1;
    BigInt() {}
    BigInt(long long v) { *this = v; }
    BigInt(const string &s) { read(s); }
    inline BigInt &operator=(long long v) { sign = v < 0 ? -1 : 1; unsigned long long x = v < 0 ? (unsigned long long)(-(v + 1)) + 1 : (unsigned long long)v; a.clear(); for (; x; x /= base) { a.push_back((int)(x % base)); } if (a.empty()) { sign = 1; } return *this; }
    inline BigInt &read(const string &s) { sign = 1, a.clear(); int p = 0; for (; p < (int)s.size() && isspace((unsigned char)s[p]); p++) {} if (p < (int)s.size() && (s[p] == '-' || s[p] == '+')) { if (s[p] == '-') { sign = -1; } p++; } int e = (int)s.size(); for (; e > p && isspace((unsigned char)s[e - 1]); e--) {}
        for (int i = e; i > p; i -= base_digits) { int x = 0, l = max(p, i - base_digits); for (int j = l; j < i; j++) { x = x * 10 + s[j] - '0'; } a.push_back(x); } trim(); return *this;
    }
    friend inline istream &operator>>(istream &is, BigInt &v) { string s; is >> s; v.read(s); return is; }
    friend inline ostream &operator<<(ostream &os, const BigInt &v) { if (v.sign == -1 && !v.is_zero()) { os << '-'; } if (v.a.empty()) { os << '0'; return os; } os << v.a.back(); for (int i = (int)v.a.size() - 2; i >= 0; i--) { os << setw(base_digits) << setfill('0') << v.a[i]; } os << setfill(' '); return os; }
    inline bool is_zero() const { return a.empty(); }
    inline BigInt abs() const { BigInt r = *this; r.sign = 1; return r; }
    inline void trim() { for (; !a.empty() && a.back() == 0; a.pop_back()) {} if (a.empty()) { sign = 1; } return; }
    static inline int abs_compare(const BigInt &x, const BigInt &y) { if (x.a.size() != y.a.size()) { return x.a.size() < y.a.size() ? -1 : 1; } for (int i = (int)x.a.size() - 1; i >= 0; i--) { if (x.a[i] != y.a[i]) { return x.a[i] < y.a[i] ? -1 : 1; } } return 0; }
    friend inline bool operator==(const BigInt &x, const BigInt &y) { return x.sign == y.sign && x.a == y.a; }
    friend inline bool operator!=(const BigInt &x, const BigInt &y) { return !(x == y); }
    friend inline bool operator<(const BigInt &x, const BigInt &y) { if (x.sign != y.sign) { return x.sign < y.sign; } int c = abs_compare(x, y); return x.sign == 1 ? c < 0 : c > 0; }
    friend inline bool operator>(const BigInt &x, const BigInt &y) { return y < x; }
    friend inline bool operator<=(const BigInt &x, const BigInt &y) { return !(y < x); }
    friend inline bool operator>=(const BigInt &x, const BigInt &y) { return !(x < y); }
    inline BigInt operator-() const { BigInt r = *this; if (!r.is_zero()) { r.sign = -r.sign; } return r; }
    static inline void add_abs(BigInt &x, const BigInt &y) { int carry = 0; if (x.a.size() < y.a.size()) { x.a.resize(y.a.size()); } for (int i = 0; i < (int)x.a.size(); i++) { long long cur = carry + x.a[i] + (i < (int)y.a.size() ? y.a[i] : 0LL); carry = cur >= base; if (carry) { cur -= base; } x.a[i] = (int)cur; } if (carry) { x.a.push_back(carry); } return; }
    // Requires |x| >= |y|.
    static inline void sub_abs(BigInt &x, const BigInt &y) { int carry = 0; for (int i = 0; i < (int)y.a.size() || carry; i++) { long long cur = x.a[i] - (i < (int)y.a.size() ? y.a[i] : 0LL) - carry; carry = cur < 0; if (carry) { cur += base; } x.a[i] = (int)cur; } x.trim(); return; }
    inline BigInt &operator+=(const BigInt &v) { if (sign == v.sign) { add_abs(*this, v); } else { int c = abs_compare(*this, v); if (c >= 0) { sub_abs(*this, v); } else { BigInt t = v; sub_abs(t, *this); *this = t; } } return *this; }
    inline BigInt &operator-=(const BigInt &v) { return *this += -v; }
    friend inline BigInt operator+(BigInt a, const BigInt &b) { return a += b; }
    friend inline BigInt operator-(BigInt a, const BigInt &b) { return a -= b; }
    inline BigInt &operator*=(int v) { ll m = v; if (m < 0) { sign = -sign, m = -m; } ll carry = 0; for (int i = 0; i < (int)a.size() || carry; i++) { if (i == (int)a.size()) { a.push_back(0); } ll cur = carry + (ll)a[i] * m; a[i] = (int)(cur % base), carry = cur / base; } trim(); return *this; }
    inline BigInt &operator/=(int v) { if (!v) { throw runtime_error("BigInt division by zero"); } ll d = v; if (d < 0) { sign = -sign, d = -d; } ll rem = 0; for (int i = (int)a.size() - 1; i >= 0; i--) { ll cur = a[i] + rem * base; a[i] = (int)(cur / d), rem = cur % d; } trim(); return *this; }
    inline int operator%(int v) const { if (!v) { throw runtime_error("BigInt modulo by zero"); } ll d = v, m = 0; if (d < 0) { d = -d; } for (int i = (int)a.size() - 1; i >= 0; i--) { m = (a[i] + m * base) % d; } return (int)(m * sign); }
    friend inline BigInt operator*(BigInt a, int v) { return a *= v; }
    friend inline BigInt operator*(int v, BigInt a) { return a *= v; }
    friend inline BigInt operator/(BigInt a, int v) { return a /= v; }
    static inline vector<int> to_base1000(const BigInt &x) { vector<int> d; d.reserve(x.a.size() * 3); for (int v : x.a) { d.push_back(v % 1000); v /= 1000; d.push_back(v % 1000); v /= 1000; d.push_back(v); } for (; !d.empty() && d.back() == 0; d.pop_back()) {} return d; }
    static inline BigInt from_base1000(vector<ll> c, int sgn) { const ll B = 1000; ll carry = 0; for (int i = 0; i < (int)c.size() || carry; i++) { if (i == (int)c.size()) { c.push_back(0); } ll cur = c[i] + carry; c[i] = cur % B, carry = cur / B; } for (; !c.empty() && c.back() == 0; c.pop_back()) {} BigInt r; r.sign = sgn;
        for (int i = 0; i < (int)c.size(); i += 3) { ll v = c[i]; if (i + 1 < (int)c.size()) { v += c[i + 1] * 1000LL; } if (i + 2 < (int)c.size()) { v += c[i + 2] * 1000000LL; } r.a.push_back((int)v); } r.trim(); return r;
    }
    static inline BigInt multiply_schoolbook(const BigInt &x, const BigInt &y) {
        BigInt r;
        r.sign = x.sign * y.sign;
        r.a.assign(x.a.size() + y.a.size(), 0);
#ifdef __SIZEOF_INT128__
        for (int i = 0; i < (int)x.a.size(); i++) {
            u128 carry = 0;
            for (int j = 0; j < (int)y.a.size() || carry; j++) {
                u128 cur = r.a[i + j] + carry;
                if (j < (int)y.a.size()) { cur += (u128)x.a[i] * y.a[j]; }
                r.a[i + j] = (int)(cur % base);
                carry = cur / base;
            }
        }
#else
        vector<int> dx = to_base1000(x), dy = to_base1000(y);
        vector<long long> c(dx.size() + dy.size());
        for (int i = 0; i < (int)dx.size(); i++) {
            for (int j = 0; j < (int)dy.size(); j++) { c[i + j] += (long long)dx[i] * dy[j]; }
        }
        r = from_base1000(c, x.sign * y.sign);
#endif
        r.trim();
        return r;
    }
    static inline BigInt multiply_fast(const BigInt &x, const BigInt &y, bool use_ntt) { vector<int> dx = to_base1000(x), dy = to_base1000(y); vector<long long> c; if (use_ntt) { c = BIG_INTEGER_DETAIL::convolution_ntt_crt(dx, dy); } else { c = BIG_INTEGER_DETAIL::convolution_karatsuba(dx, dy); } return from_base1000(c, x.sign * y.sign); }
    inline BigInt &operator*=(const BigInt &v) { if (is_zero() || v.is_zero()) { *this = 0; return *this; } int n = (int)min(a.size(), v.a.size()); if (n < 16) { *this = multiply_schoolbook(*this, v); } else if (n < 96) { *this = multiply_fast(*this, v, false); } else { *this = multiply_fast(*this, v, true); } return *this; }
    friend inline BigInt operator*(BigInt a, const BigInt &b) { return a *= b; }
    static inline pair<BigInt, BigInt> divmod(const BigInt &a1, const BigInt &b1) { if (b1.is_zero()) { throw runtime_error("BigInt division by zero"); } int norm = (int)(base / ((ll)b1.a.back() + 1)); BigInt a = a1.abs() * norm, b = b1.abs() * norm, q, r; q.a.assign(a.a.size(), 0);
        for (int i = (int)a.a.size() - 1; i >= 0; i--) { r.a.insert(r.a.begin(), a.a[i]), r.trim(); ll s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()], s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1], d = ((ll)base * s1 + s2) / b.a.back(); if (d >= base) { d = base - 1; } r -= b * (int)d; for (; r.sign == -1; d--) { r += b; } q.a[i] = (int)d; }
        q.sign = a1.sign * b1.sign, r.sign = a1.sign, q.trim(), r.trim(), r /= norm; return {q, r};
    }
    inline BigInt &operator/=(const BigInt &v) { *this = divmod(*this, v).first; return *this; }
    inline BigInt &operator%=(const BigInt &v) { *this = divmod(*this, v).second; return *this; }
    friend inline BigInt operator/(BigInt a, const BigInt &b) { return a /= b; }
    friend inline BigInt operator%(BigInt a, const BigInt &b) { return a %= b; }
    inline BigInt &operator++() { return *this += 1; }
    inline BigInt operator++(int) { BigInt t = *this; ++*this; return t; }
    inline BigInt &operator--() { return *this -= 1; }
    inline BigInt operator--(int) { BigInt t = *this; --*this; return t; }
};
inline BigInt gcd(BigInt a, BigInt b) { a.sign = b.sign = 1; for (; !b.is_zero();) { BigInt r = a % b; a = b; b = r; } return a; }
template<class T>
inline BigInt pow(BigInt a, T b) { BigInt r = 1; for (; b; b >>= 1, a *= a) { if (b & 1) { r *= a; } } return r; }
inline BigInt pow_mod(BigInt a, BigInt b, const BigInt &mod) { BigInt r = BigInt(1) % mod; a %= mod; for (; !b.is_zero(); b /= 2, a = a * a % mod) { if (b % 2 != 0) { r = r * a % mod; } } return r; }
#pragma endregion
#pragma region DATA_STRUCTURE
namespace DATA_STRUCTURE {
struct Default_Hash {
    static inline ull splitmix64(ull x) { x += 0x9e3779b97f4a7c15ULL; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL; x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL; return x ^ (x >> 31); }
    template<class T>
    inline size_t operator()(const T &x) const { static const ull seed = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64((ull)std::hash<T>()(x) + seed); }
};
template<class K, class V, int N, class Hash = Default_Hash>
struct Hash_Map {
    static const int M = N * 2 + 3;
    K key[M];
    V val[M];
    unsigned char state[M]{}; // 0 empty, 1 used, 2 deleted
    int n = 0;
    Hash hs;
    inline int locate(const K &k) const { size_t h = hs(k) % M; for (int t = 0; t < M; t++, h = (h + 1) % M) { if (state[h] == 0) { return -1; } if (state[h] == 1 && key[h] == k) { return (int)h; } } return -1; }
    inline int slot(const K &k) { size_t h = hs(k) % M; int del = -1; for (int t = 0; t < M; t++, h = (h + 1) % M) { if (state[h] == 1 && key[h] == k) { return (int)h; } if (state[h] == 2 && del == -1) { del = (int)h; } if (state[h] == 0) { return del == -1 ? (int)h : del; } } return del; }
    inline bool empty() const { return n == 0; }
    inline int size() const { return n; }
    inline bool count(const K &k) const { return locate(k) != -1; }
    inline V *find(const K &k) { int p = locate(k); return p == -1 ? nullptr : &val[p]; }
    inline const V *find(const K &k) const { int p = locate(k); return p == -1 ? nullptr : &val[p]; }
    inline V &operator[](const K &k) { int p = slot(k); if (state[p] != 1) { state[p] = 1, key[p] = k, val[p] = V(), n++; } return val[p]; }
    inline V &at(const K &k) { int p = locate(k); if (p == -1) { throw out_of_range("Hash_Map::at"); } return val[p]; }
    inline bool erase(const K &k) { int p = locate(k); if (p == -1) { return false; } state[p] = 2; n--; return true; }
    inline void clear() { memset(state, 0, sizeof(state)); n = 0; return; }
};
template<class T, int N, class Compare = less<T>>
struct Heap {
    T a[N + 1];
    int n = 0;
    Compare cmp;
    inline bool empty() const { return n == 0; }
    inline int size() const { return n; }
    inline void clear() { n = 0; return; }
    inline T &top() { return a[1]; }
    inline const T &top() const { return a[1]; }
    inline void up(int p) { for (; p > 1 && cmp(a[p >> 1], a[p]); p >>= 1) { swap(a[p >> 1], a[p]); } return; }
    inline void down(int p) { for (;;) { int q = p, l = p << 1, r = l | 1; if (l <= n && cmp(a[q], a[l])) { q = l; } if (r <= n && cmp(a[q], a[r])) { q = r; } if (q == p) { break; } swap(a[p], a[q]), p = q; } return; }
    inline void push(const T &x) { a[++n] = x; up(n); return; }
    inline void pop() { a[1] = a[n--]; if (n) { down(1); } return; }
    template<class It>
    inline void build(It first, It last) { n = 0; for (; first != last; ++first) { a[++n] = *first; } for (int i = n >> 1; i; i--) { down(i); } return; }
};
struct DSU_Base {
    static inline int find_root(int *fa, int x) { for (; fa[x] != x; x = fa[x] = fa[fa[x]]) {} return x; }
};
template<int N>
struct DSU {
    int fa[N + 1], sz[N + 1];
    inline void init(int n) { for (int i = 1; i <= n; i++) { fa[i] = i, sz[i] = 1; } return; }
    inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    inline bool same(int x, int y) { return find(x) == find(y); }
    inline bool merge(int x, int y) { x = find(x), y = find(y); if (x == y) { return false; } if (sz[x] < sz[y]) { swap(x, y); } fa[y] = x, sz[x] += sz[y]; return true; }
    inline int size(int x) { return sz[find(x)]; }
};
template<class T, int N, class Compare = less<T>>
struct Leftist_Heap {
    struct Node {
        T val;
        int l = 0, r = 0, dis = 0;
    } tr[N + 1];
    int tot = 0, rt = 0, n = 0;
    Compare cmp;
    inline bool better(const T &a, const T &b) const { return cmp(b, a); }
    inline int merge_node(int x, int y) { if (!x || !y) { return x | y; } if (better(tr[y].val, tr[x].val)) { swap(x, y); } tr[x].r = merge_node(tr[x].r, y); if (tr[tr[x].l].dis < tr[tr[x].r].dis) { swap(tr[x].l, tr[x].r); } tr[x].dis = tr[tr[x].r].dis + 1; return x; }
    inline bool empty() const { return n == 0; }
    inline int size() const { return n; }
    inline const T &top() const { return tr[rt].val; }
    inline void clear() { tot = rt = n = 0; return; }
    inline int insert(const T &x) { int p = ++tot; tr[p].val = x, tr[p].l = tr[p].r = 0, tr[p].dis = 1, rt = merge_node(rt, p), n++; return p; }
    inline void push(const T &x) { insert(x); return; }
    inline void pop() { rt = merge_node(tr[rt].l, tr[rt].r); n--; return; }
    inline void merge(Leftist_Heap &other) { /* Pool-owning heaps cannot safely merge nodes from different objects. */ for (; !other.empty();) { push(other.top()); other.pop(); } return; }
};
template<class T, int N, class Compare = less<T>>
struct Pairing_Heap {
    struct Node {
        T val;
        int child = 0, next = 0, prev = 0;
        bool alive = false;
    } tr[N + 1];
    int tot = 0, rt = 0, n = 0;
    Compare cmp;
    inline bool better(const T &a, const T &b) const { return cmp(b, a); }
    inline int meld(int x, int y) { if (!x || !y) { return x | y; } if (better(tr[y].val, tr[x].val)) { swap(x, y); } tr[y].prev = x, tr[y].next = tr[x].child; if (tr[x].child) { tr[tr[x].child].prev = y; } tr[x].child = y; return x; }
    inline int merge_pairs(int x) { if (!x) { return 0; } vector<int> v; for (int p = x; p;) { int a = p, b = tr[a].next; p = b ? tr[b].next : 0; tr[a].prev = tr[a].next = 0; if (b) { tr[b].prev = tr[b].next = 0; v.push_back(meld(a, b)); } else { v.push_back(a); } } int r = 0; for (int i = (int)v.size() - 1; i >= 0; i--) { r = meld(r, v[i]); } return r; }
    inline void cut(int p) { int q = tr[p].prev; if (!q) { return; } if (tr[q].child == p) { tr[q].child = tr[p].next; if (tr[p].next) { tr[tr[p].next].prev = q; } } else { tr[q].next = tr[p].next; if (tr[p].next) { tr[tr[p].next].prev = q; } } tr[p].prev = tr[p].next = 0; return; }
    inline bool empty() const { return n == 0; }
    inline int size() const { return n; }
    inline const T &top() const { return tr[rt].val; }
    inline void clear() { tot = rt = n = 0; return; }
    inline int insert(const T &x) { int p = ++tot; tr[p].val = x, tr[p].child = tr[p].next = tr[p].prev = 0, tr[p].alive = true, rt = meld(rt, p), n++; return p; }
    inline void push(const T &x) { insert(x); return; }
    inline void pop() { int old = rt; int c = tr[old].child; if (c) { tr[c].prev = 0; } rt = merge_pairs(c); tr[old].alive = false; tr[old].child = tr[old].next = tr[old].prev = 0; n--; return; }
    inline bool improve(int p, const T &x) { if (!tr[p].alive || !better(x, tr[p].val)) { return false; } tr[p].val = x; if (p != rt) { cut(p); rt = meld(rt, p); } return true; }
    inline bool erase(int p) { if (!tr[p].alive) { return false; } if (p == rt) { pop(); return true; } cut(p); int sub = merge_pairs(tr[p].child); tr[p].alive = false; tr[p].child = tr[p].next = tr[p].prev = 0; rt = meld(rt, sub); n--; return true; }
};
template<class T, int N, class Compare = less<T>>
struct Fibonacci_Heap {
    struct Node {
        T val;
        int parent = 0, child = 0, left = 0, right = 0, degree = 0;
        bool mark = false, alive = false;
    } tr[N + 1];
    int tot = 0, rt = 0, n = 0;
    Compare cmp;
    inline bool better(const T &a, const T &b) const { return cmp(b, a); }
    inline void singleton(int p) { tr[p].left = tr[p].right = p; return; }
    inline void remove_from_list(int p) { tr[tr[p].left].right = tr[p].right; tr[tr[p].right].left = tr[p].left; singleton(p); return; }
    inline void add_after(int x, int p) { tr[p].left = x; tr[p].right = tr[x].right; tr[tr[x].right].left = p; tr[x].right = p; return; }
    inline void add_root(int p) { tr[p].parent = 0, tr[p].mark = false; if (!rt) { singleton(p), rt = p; } else { add_after(rt, p); if (better(tr[p].val, tr[rt].val)) { rt = p; } } return; }
    inline vector<int> list_nodes(int p) const { vector<int> v; if (!p) { return v; } int x = p; do { v.push_back(x); x = tr[x].right; } while (x != p); return v; }
    inline void link_as_child(int y, int x) { remove_from_list(y), tr[y].parent = x, tr[y].mark = false; if (!tr[x].child) { tr[x].child = y, singleton(y); } else { add_after(tr[x].child, y); } tr[x].degree++; return; }
    inline void consolidate() { if (!rt) { return; } int D = 1; for (int x = n; x; x >>= 1) { D++; } vector<int> A(D + 5, 0), roots = list_nodes(rt);
        for (int x : roots) { if (tr[x].parent) { continue; } int d = tr[x].degree; for (; A[d]; d++) { int y = A[d]; if (better(tr[y].val, tr[x].val)) { swap(x, y); } link_as_child(y, x), A[d] = 0; } A[d] = x; }
        rt = 0; for (int x : A) { if (!x || tr[x].parent) { continue; } singleton(x); if (!rt) { rt = x; } else { add_after(rt, x); if (better(tr[x].val, tr[rt].val)) { rt = x; } } } return;
    }
    inline void cut(int x, int y) { if (tr[y].child == x) { if (tr[x].right == x) { tr[y].child = 0; } else { tr[y].child = tr[x].right; } } remove_from_list(x); tr[y].degree--; add_root(x); return; }
    inline void cascading_cut(int y) { int z = tr[y].parent; if (!z) { return; } if (!tr[y].mark) { tr[y].mark = true; } else { cut(y, z); cascading_cut(z); } return; }
    inline bool empty() const { return n == 0; }
    inline int size() const { return n; }
    inline const T &top() const { return tr[rt].val; }
    inline void clear() { tot = rt = n = 0; return; }
    inline int insert(const T &x) { int p = ++tot; tr[p].val = x, tr[p].parent = tr[p].child = 0, tr[p].degree = 0, tr[p].mark = false, tr[p].alive = true; singleton(p), add_root(p), n++; return p; }
    inline void push(const T &x) { insert(x); return; }
    inline void pop() { int z = rt; vector<int> children = list_nodes(tr[z].child); for (int x : children) { remove_from_list(x); add_root(x); } tr[z].child = 0; if (tr[z].right == z) { rt = 0; } else { int nr = tr[z].right; remove_from_list(z); rt = nr; } tr[z].alive = false; n--; if (rt) { consolidate(); } return; }
    inline bool improve(int x, const T &v) { if (!tr[x].alive || !better(v, tr[x].val)) { return false; } tr[x].val = v; int y = tr[x].parent; if (y && better(tr[x].val, tr[y].val)) { cut(x, y); cascading_cut(y); } if (better(tr[x].val, tr[rt].val)) { rt = x; } return true; }
};
template<int N, int Sigma = 26, char Base = 'a'>
struct Trie {
    int ch[N + 1][Sigma], cnt[N + 1], pass[N + 1], tot = 1;
    inline void clear() { memset(ch, 0, sizeof(ch)); memset(cnt, 0, sizeof(cnt)); memset(pass, 0, sizeof(pass)); tot = 1; return; }
    inline void insert(const string &s) { int p = 1; pass[p]++; for (char c : s) { int x = c - Base; if (!ch[p][x]) { ch[p][x] = ++tot; } p = ch[p][x], pass[p]++; } cnt[p]++; return; }
    inline int count(const string &s) const { int p = 1; for (char c : s) { int x = c - Base; if (x < 0 || x >= Sigma || !ch[p][x]) { return 0; } p = ch[p][x]; } return cnt[p]; }
    inline int prefix_count(const string &s) const { int p = 1; for (char c : s) { int x = c - Base; if (x < 0 || x >= Sigma || !ch[p][x]) { return 0; } p = ch[p][x]; } return pass[p]; }
};
template<int N, int B = 63>
struct Binary_Trie {
    int ch[N + 1][2], cnt[N + 1], tot = 1;
    inline void clear() { memset(ch, 0, sizeof(ch)); memset(cnt, 0, sizeof(cnt)); tot = 1; return; }
    inline void insert(ull x) { int p = 1; cnt[p]++; for (int i = B - 1; i >= 0; i--) { int b = (x >> i) & 1; if (!ch[p][b]) { ch[p][b] = ++tot; } p = ch[p][b], cnt[p]++; } return; }
    inline bool erase(ull x) { int p = 1; if (!cnt[p]) { return false; } int path[B + 1]; path[0] = p; for (int i = B - 1, k = 0; i >= 0; i--, k++) { int b = (x >> i) & 1; if (!ch[p][b] || !cnt[ch[p][b]]) { return false; } p = ch[p][b], path[k + 1] = p; } for (int i = 0; i <= B; i++) { cnt[path[i]]--; } return true; }
    inline ull max_xor(ull x) const { int p = 1; ull r = 0; for (int i = B - 1; i >= 0; i--) { int b = (x >> i) & 1, q = b ^ 1; if (ch[p][q] && cnt[ch[p][q]]) { r |= 1ULL << i; p = ch[p][q]; } else { p = ch[p][b]; } } return r; }
};
template<class T, int N, class Compare = less<T>>
struct Treap {
    struct Node {
        T key;
        ull pri = 0;
        int l = 0, r = 0, sz = 0, cnt = 0;
    } tr[N + 1];
    int rt = 0, tot = 0;
    Compare cmp;
    inline int size(int p) const { return p ? tr[p].sz : 0; }
    inline void pull(int p) { tr[p].sz = size(tr[p].l) + size(tr[p].r) + tr[p].cnt; return; }
    inline bool equal_key(const T &a, const T &b) const { return !cmp(a, b) && !cmp(b, a); }
    inline int new_node(const T &x) { int p = ++tot; tr[p].key = x; tr[p].pri = RANDOM::next_u64(); tr[p].l = tr[p].r = 0; tr[p].sz = tr[p].cnt = 1; return p; }
    inline void rotate_left(int &p) { int q = tr[p].r; tr[p].r = tr[q].l, tr[q].l = p; pull(p), pull(q), p = q; return; }
    inline void rotate_right(int &p) { int q = tr[p].l; tr[p].l = tr[q].r, tr[q].r = p; pull(p), pull(q), p = q; return; }
    inline void insert(int &p, const T &x) { if (!p) { p = new_node(x); return; } if (equal_key(x, tr[p].key)) { tr[p].cnt++; } else if (cmp(x, tr[p].key)) { insert(tr[p].l, x); if (tr[tr[p].l].pri > tr[p].pri) { rotate_right(p); } } else { insert(tr[p].r, x); if (tr[tr[p].r].pri > tr[p].pri) { rotate_left(p); } } pull(p); return; }
    inline void insert(const T &x) { insert(rt, x); return; }
    inline bool erase(int &p, const T &x) { if (!p) { return false; } bool ok = false; if (equal_key(x, tr[p].key)) { ok = true; if (tr[p].cnt > 1) { tr[p].cnt--; } else if (!tr[p].l || !tr[p].r) { p = tr[p].l | tr[p].r; return true; } else if (tr[tr[p].l].pri > tr[tr[p].r].pri) { rotate_right(p); erase(tr[p].r, x); } else { rotate_left(p); erase(tr[p].l, x); } } else if (cmp(x, tr[p].key)) { ok = erase(tr[p].l, x); } else { ok = erase(tr[p].r, x); } if (p) { pull(p); } return ok; }
    inline bool erase(const T &x) { return erase(rt, x); }
    inline int count(const T &x) const { int p = rt; for (; p;) { if (equal_key(x, tr[p].key)) { return tr[p].cnt; } p = cmp(x, tr[p].key) ? tr[p].l : tr[p].r; } return 0; }
    inline int rank(const T &x) const { int p = rt, r = 1; for (; p;) { if (cmp(x, tr[p].key)) { p = tr[p].l; } else { r += size(tr[p].l); if (equal_key(x, tr[p].key)) { return r; } r += tr[p].cnt; p = tr[p].r; } } return r; }
    inline const T &kth(int k) const { int p = rt; for (;;) { int lsz = size(tr[p].l); if (k <= lsz) { p = tr[p].l; } else if (k <= lsz + tr[p].cnt) { return tr[p].key; } else { k -= lsz + tr[p].cnt; p = tr[p].r; } } }
    inline int size() const { return size(rt); }
    inline bool empty() const { return rt == 0; }
    inline void clear() { rt = tot = 0; return; }
};
template<class T, int N, class Compare = less<T>>
struct FHQ_Treap {
    struct Node {
        T key;
        ull pri = 0;
        int l = 0, r = 0, sz = 0;
    } tr[N + 1];
    int rt = 0, tot = 0;
    Compare cmp;
    inline int size(int p) const { return p ? tr[p].sz : 0; }
    inline void pull(int p) { tr[p].sz = size(tr[p].l) + size(tr[p].r) + 1; return; }
    inline bool leq(const T &a, const T &b) const { return !cmp(b, a); }
    inline int new_node(const T &x) { int p = ++tot; tr[p].key = x; tr[p].pri = RANDOM::next_u64(); tr[p].l = tr[p].r = 0; tr[p].sz = 1; return p; }
    inline void split(int p, const T &x, int &a, int &b) { if (!p) { a = b = 0; return; } if (leq(tr[p].key, x)) { a = p; split(tr[p].r, x, tr[p].r, b); pull(a); } else { b = p; split(tr[p].l, x, a, tr[p].l); pull(b); } return; }
    inline int merge(int a, int b) { if (!a || !b) { return a | b; } if (tr[a].pri > tr[b].pri) { tr[a].r = merge(tr[a].r, b); pull(a); return a; } tr[b].l = merge(a, tr[b].l); pull(b); return b; }
    inline void insert(const T &x) { int a, b; split(rt, x, a, b); rt = merge(merge(a, new_node(x)), b); return; }
    inline bool erase(const T &x) { int a = 0, b = 0, c = 0; split_less(rt, x, a, b); split(b, x, b, c); if (!b) { rt = merge(a, c); return false; } b = merge(tr[b].l, tr[b].r); rt = merge(merge(a, b), c); return true; }
    inline void split_less(int p, const T &x, int &a, int &b) { if (!p) { a = b = 0; return; } if (cmp(tr[p].key, x)) { a = p; split_less(tr[p].r, x, tr[p].r, b); pull(a); } else { b = p; split_less(tr[p].l, x, a, tr[p].l); pull(b); } return; }
    inline int rank(const T &x) { int a, b; split_less(rt, x, a, b); int r = size(a) + 1; rt = merge(a, b); return r; }
    inline const T &kth(int k) const { int p = rt; for (;;) { int lsz = size(tr[p].l); if (k == lsz + 1) { return tr[p].key; } if (k <= lsz) { p = tr[p].l; } else { k -= lsz + 1; p = tr[p].r; } } }
    inline int size() const { return size(rt); }
    inline bool empty() const { return rt == 0; }
    inline void clear() { rt = tot = 0; return; }
};
template<class T, int N>
struct Link_Cut_Tree {
    int ch[N + 1][2], fa[N + 1], stk[N + 1];
    bool rev[N + 1];
    T val[N + 1], sum[N + 1];
    inline bool is_root(int x) const { int f = fa[x]; return !f || (ch[f][0] != x && ch[f][1] != x); }
    inline void pull(int x) { sum[x] = sum[ch[x][0]] + val[x] + sum[ch[x][1]]; return; }
    inline void apply_reverse(int x) { if (!x) { return; } swap(ch[x][0], ch[x][1]), rev[x] ^= 1; return; }
    inline void push(int x) { if (rev[x]) { apply_reverse(ch[x][0]), apply_reverse(ch[x][1]), rev[x] = false; } return; }
    inline void rotate(int x) { int y = fa[x], z = fa[y], k = ch[y][1] == x, w = ch[x][k ^ 1]; if (!is_root(y)) { ch[z][ch[z][1] == y] = x; } fa[x] = z, ch[x][k ^ 1] = y, fa[y] = x, ch[y][k] = w; if (w) { fa[w] = y; } pull(y), pull(x); return; }
    inline void splay(int x) { int top = 0; stk[++top] = x; for (int y = x; !is_root(y); y = fa[y]) { stk[++top] = fa[y]; } for (; top; top--) { push(stk[top]); } for (; !is_root(x); rotate(x)) { int y = fa[x], z = fa[y]; if (!is_root(y)) { if ((ch[y][0] == x) ^ (ch[z][0] == y)) { rotate(x); } else { rotate(y); } } } return; }
    inline int access(int x) { int y = 0; for (int p = x; p; p = fa[p]) { splay(p), ch[p][1] = y, pull(p), y = p; } splay(x); return y; }
    inline void make_root(int x) { access(x), apply_reverse(x); return; }
    inline int find_root(int x) { access(x); for (;;) { push(x); if (!ch[x][0]) { break; } x = ch[x][0]; } splay(x); return x; }
    inline bool connected(int x, int y) { if (x == y) { return true; } make_root(x); return find_root(y) == x; }
    inline bool link(int x, int y) { make_root(x); if (find_root(y) == x) { return false; } fa[x] = y; return true; }
    inline bool cut(int x, int y) { make_root(x), access(y); if (ch[y][0] != x || ch[x][1]) { return false; } ch[y][0] = fa[x] = 0, pull(y); return true; }
    inline void split(int x, int y) { make_root(x), access(y); return; }
    inline void set_value(int x, const T &v) { access(x), val[x] = v, pull(x); return; }
    inline T query_path(int x, int y) { split(x, y); return sum[y]; }
    inline void init(int n) { for (int i = 0; i <= n; i++) { ch[i][0] = ch[i][1] = fa[i] = 0, rev[i] = false, val[i] = sum[i] = T(); } return; }
};
} // namespace DATA_STRUCTURE
#pragma endregion
inline void solve(int Task_Id);
} // namespace TANGYIXIAO
using namespace TANGYIXIAO;
// clang-format on
#pragma endregion TANGYIXIAO
#pragma region MAIN
signed main() {
#ifdef TIME_COUNT
    Start_Time_Count();
#endif
    IOSS_Init();
#if JUDGE_TYPE == 1
    Judge_File(FILE_NAME);
#elif JUDGE_TYPE == 2
    Local_File(FILE_NAME, FILE_INDEX);
#endif
    int T = 1;
#ifdef MULTIPLE_TEST
    cin >> T;
#endif
    for (int Task_Id = 1; Task_Id <= T; Task_Id++) {
        solve(Task_Id);
    }
#ifdef TIME_COUNT
    End_Time_Count();
    Print_Time_Count("TOTAL");
#endif
    return EXIT_SUCCESS;
}
#pragma endregion MAIN
#pragma endregion PREPROCESSOR
namespace TANGYIXIAO {
const int DICE_N = 505;
BigInt f[DICE_N], g[DICE_N];
int ans[DICE_N];

inline void solve(int Task_Id) {
    int a[6], w[6] = {0, 4, 6, 8, 12, 20};

    for (int i = 1; i <= 5; i++) {
        cin >> a[i];
    }

    f[0] = 1;

    int mx = 0, mn = 0;

    for (int p = 1; p <= 5; p++) {
        for (int z = 1; z <= a[p]; z++) {
            for (int s = 0; s <= mx + w[p]; s++) {
                g[s] = 0;
            }

            for (int s = mn; s <= mx; s++) {
                for (int x = 1; x <= w[p]; x++) {
                    g[s + x] += f[s];
                }
            }

            mn++, mx += w[p];

            for (int s = mn; s <= mx; s++) {
                f[s] = g[s];
            }
        }
    }

    int tot = 0;

    for (int s = mn; s <= mx; s++) {
        ans[++tot] = s;
    }

    sort(ans + 1, ans + tot + 1, [&](int x, int y) {
        return f[x] > f[y];
    });

    for (int i = 1; i <= tot; i++) {
        cout << ans[i] << (i == tot ? "\n" : " ");
    }

    return;
}
} // namespace TANGYIXIAO