
/*
Copyright (C) 2026 TangYixiao
*/

#define PRAGMA_TYPE 0

#define JUDGE_TYPE 0
#define FILE_INDEX 1

#define FILE_NAME ""

#pragma region PREPROCESSOR
#pragma region PRAGMAS
#if PRAGMA_TYPE == 2
#if PRAGMA_GCC_or_GPlusPlus_ALLOWED == 1
#pragma region PRAGMA_GCC
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma endregion PRAGMA_GCC

#elif PRAGMA_GCC_or_GPlusPlus_ALLOWED == 2

#pragma region PRAGMA_GPlusPlus
#pragma G++ optimize(1)
#pragma G++ optimize(2)
#pragma G++ optimize(3)
#pragma G++ optimize("Ofast")
#pragma G++ optimize("inline")
#pragma G++ optimize("-fgcse")
#pragma G++ optimize("-fgcse-lm")
#pragma G++ optimize("-fipa-sra")
#pragma G++ optimize("-ftree-pre")
#pragma G++ optimize("-ftree-vrp")
#pragma G++ optimize("-fpeephole2")
#pragma G++ optimize("-ffast-math")
#pragma G++ optimize("-fsched-spec")
#pragma G++ optimize("unroll-loops")
#pragma G++ optimize("-falign-jumps")
#pragma G++ optimize("-falign-loops")
#pragma G++ optimize("-falign-labels")
#pragma G++ optimize("-fdevirtualize")
#pragma G++ optimize("-fcaller-saves")
#pragma G++ optimize("-fcrossjumping")
#pragma G++ optimize("-fthread-jumps")
#pragma G++ optimize("-funroll-loops")
#pragma G++ optimize("-fwhole-program")
#pragma G++ optimize("-freorder-blocks")
#pragma G++ optimize("-fschedule-insns")
#pragma G++ optimize("inline-functions")
#pragma G++ optimize("-ftree-tail-merge")
#pragma G++ optimize("-fschedule-insns2")
#pragma G++ optimize("-fstrict-aliasing")
#pragma G++ optimize("-fstrict-overflow")
#pragma G++ optimize("-falign-functions")
#pragma G++ optimize("-fcse-skip-blocks")
#pragma G++ optimize("-fcse-follow-jumps")
#pragma G++ optimize("-fsched-interblock")
#pragma G++ optimize("-fpartial-inlining")
#pragma G++ optimize("no-stack-protector")
#pragma G++ optimize("-freorder-functions")
#pragma G++ optimize("-findirect-inlining")
#pragma G++ optimize("-frerun-cse-after-loop")
#pragma G++ optimize("inline-small-functions")
#pragma G++ optimize("-finline-small-functions")
#pragma G++ optimize("-ftree-switch-conversion")
#pragma G++ optimize("-foptimize-sibling-calls")
#pragma G++ optimize("-fexpensive-optimizations")
#pragma G++ optimize("-funsafe-loop-optimizations")
#pragma G++ optimize("inline-functions-called-once")
#pragma G++ optimize("-fdelete-null-pointer-checks")
#pragma endregion PRAGMA_GPlusPlus
#else
#endif
#elif PRAGMA_TYPE == 1

#pragma GCC optimize("O3")

/*
#pragma GCC optimize("Ofast,no-stack-protector")

#pragma GCC optimize("Ofast")
#pragma GCC target("sse3","sse2","sse")
#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC diagnostic error "-std=c++14"
*/
#elif PRAGMA_TYPE == 3

#pragma region PRAGMA_COMPILER
#pragma region Optimization

/*
#pragma GCC optimize("O0")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Og")


#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("tree-vectorize")
*/
#pragma endregion Optimization
#pragma region Target_Architecture
/*
#pragma GCC target("arch=native")
#pragma GCC target("arch=core2")
#pragma GCC target("tune=generic")
#pragma GCC target("tune=intel")
#pragma GCC target("sse2")
#pragma GCC target("sse4.2")
#pragma GCC target("avx")
#pragma GCC target("avx2")
#pragma GCC target("fma")
#pragma GCC target("bmi2")
#pragma GCC target("popcnt")
#pragma GCC target("crc32")
#pragma GCC target("no-sse")


#pragma GCC target("thumb")
#pragma GCC target("arm")
#pragma GCC target("arch=armv7-a")
#pragma GCC target("mfpu=neon")
#pragma GCC target("mfloat-abi=hard")
*/
#pragma endregion Target_Architecture
#pragma region Diagnostic_Warnings
/*

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic warning "-Wunused-parameter"
#pragma GCC diagnostic error "-Wformat-security"


#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic error "-Wextra"


#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic warning "-Wshadow"
#pragma GCC diagnostic error "-Wnull-dereference"
#pragma GCC diagnostic error "-Wmaybe-uninitialized"


#pragma GCC diagnostic error "-Wpedantic"
#pragma GCC diagnostic warning "-Wpedantic"


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

#pragma GCC diagnostic pop
*/
#pragma endregion Diagnostic_Warnings
#pragma region Visibility_Linking
/*
#pragma GCC visibility push(hidden)

#pragma GCC visibility pop

#pragma GCC visibility push(default)

#pragma GCC visibility pop


*/
#pragma endregion Visibility_Linking
#pragma region Stack Protection_Security
/*

#pragma GCC optimize("stack-protector-strong")
#pragma GCC optimize("no-stack-protector")



*/
#pragma endregion Stack Protection_Security
#pragma region Miscellaneous_Code_Generation
/*


#pragma GCC optimize("fPIC")


#pragma GCC optimize("no-exceptions")


#pragma GCC optimize("no-rtti")


#pragma GCC optimize("inline-limit=100")
*/
#pragma endregion Miscellaneous_Code_Generation
#pragma region Pushing_Popping_Options
/*

#pragma GCC push_options
#pragma GCC optimize("O3")
#pragma GCC target("avx2")

#pragma GCC pop_options
*/
#pragma endregion Pushing_Popping_Options
#pragma endregion PRAGMA_COMPILER
#else
#endif
#pragma endregion PRAGMAS

#pragma region INCLUDES

#ifdef TESTLIB
#include <testlib.h>
#endif

#ifdef BITS_NOT_ALLOWED

#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cfloat>
#include <climits>
#include <csetjmp>
#include <cstdarg>
#include <cstddef>
#include <cstdlib>

#if __cplusplus >= 201103L
#include <cstdint>
#if __cplusplus < 201703L
#include <ciso646>
#endif
#endif

#include <algorithm>
#include <bitset>
#include <functional>
#include <iterator>
#include <limits>
#include <memory>
#include <new>
#include <numeric>
#include <typeinfo>
#include <utility>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <initializer_list>
#include <ratio>
#include <scoped_allocator>
#include <tuple>
#include <type_traits>
#include <typeindex>

#endif

#if __cplusplus >= 201402L

#endif

#if __cplusplus >= 201703L
#include <any>

#include <optional>
#include <string_view>
#include <variant>

#endif

#if __cplusplus >= 202002L
#include <bit>
#include <compare>
#include <concepts>
#include <numbers>
#include <ranges>
#include <source_location>
#include <span>
#include <version>

#if __cpp_impl_coroutine
#include <coroutine>
#endif
#endif

#if __cplusplus > 202002L
#include <expected>
#include <stdatomic.h>
#endif

#if _GLIBCXX_HOSTED

#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#if __cplusplus >= 201103L
#include <cfenv>
#include <cinttypes>
#include <cstdint>
#include <cuchar>
#if __cplusplus < 201703L
#include <ccomplex>
#include <cstdalign>
#include <cstdbool>
#include <ctgmath>
#endif
#endif

#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>

#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#if __cplusplus >= 201703L
#include <any>
#include <charconv>

#include <filesystem>
#include <memory_resource>
#include <optional>
#include <variant>

#endif

#if __cplusplus >= 202002L
#include <barrier>
#include <bit>
#include <compare>
#include <concepts>
#include <format>
#include <latch>
#include <numbers>
#include <ranges>
#include <semaphore>
#include <source_location>
#include <span>
#include <stop_token>
#include <syncstream>
#include <version>

#endif

#if __cplusplus > 202002L
#include <expected>
#include <flat_map>
#include <flat_set>
#include <generator>
#include <print>
#include <spanstream>
#include <stacktrace>
#include <stdatomic.h>
#include <stdfloat>
#endif

#if __cplusplus > 202302L
#include <stdbit.h>
#include <stdckdint.h>
#include <text_encoding>

#endif

#endif

#else
#include <bits/stdc++.h>
#endif
using namespace std;

/*

注意在用 priority_queue 时，可能会和 std 的冲突。

*/

#ifdef PD_DS_USED
#ifdef BITS_NOT_ALLOWED

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/exception.hpp>
#include <ext/pb_ds/hash_fn>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/list_update_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;

#else

#include <bits/extc++.h>
using namespace __gnu_pbds;

#endif

#endif
#pragma endregion INCLUDES

#pragma region TANGYIXIAO
namespace TANGYIXIAO {
#pragma region IO
namespace IO {
inline void Init_IO() { cin.tie(0)->sync_with_stdio(false); }
#pragma region FILE_IO
namespace FILE_IO {
const string Insuffix = ".in", Outsuffix = ".out", Anssuffix = ".ans";
inline void Judge_File(string File_Name) { freopen((File_Name + Insuffix).c_str(), "r", stdin), freopen((File_Name + Outsuffix).c_str(), "w", stdout); }
inline void Local_File(string File_Name, int File_Idx) { freopen((File_Name + to_string(File_Idx) + Insuffix).c_str(), "r", stdin), freopen((File_Name + to_string(File_Idx) + Outsuffix).c_str(), "w", stdout); }
} // namespace FILE_IO
using namespace FILE_IO;
#pragma endregion FILE_IO
#pragma region INT128_IO
namespace INT128_IO {

istream &operator>>(istream &is, __int128 &x) {
    string s;
    is >> s;
    bool neg = false;
    x = 0;
    for (char c : s) {
        if (c == '-')
            neg = true;
        else
            x = x * 10 + (c - '0');
    }
    if (neg)
        x = -x;
    return is;
}
ostream &operator<<(ostream &os, __int128 x) {
    if (x == 0)
        os << 0;
    else {
        string s, t;
        if (x < 0)
            x = -x, t = "-";
        while (x)
            s.push_back('0' + x % 10), x /= 10;
        reverse(s.begin(), s.end());
        os << t << s;
    }
    return os;
}

} // namespace INT128_IO
using namespace INT128_IO;
#pragma endregion INT128_IO
} // namespace IO
using namespace IO;
#pragma endregion IO
#pragma region TIME
namespace TIME {
clock_t Start_Time, End_Time;
inline void Start_Time_Count() { Start_Time = clock(); }
inline void End_Time_Count() { End_Time = clock(); }
inline double Time_Count() { return (double)(End_Time - Start_Time) / CLOCKS_PER_SEC; }
inline void Print_Time_Count(string Programe_Name) { cerr << fixed << setprecision(4) << "\n" + Programe_Name + " Time: " << Time_Count() << "s\n"; }
} // namespace TIME
using namespace TIME;
#pragma endregion TIME
#pragma region DEBUGS
namespace DEBUGS {
#define all(x) (x).begin(), (x).end()
#define fprint(...) cout << format(__VA_ARGS__)
#define fprintln(...) cout << format(__VA_ARGS__) << '\n'
#define ferr(...) cerr << format(__VA_ARGS__)
#define ferrln(...) cerr << format(__VA_ARGS__) << '\n'
#define funct(name, ret, ...) function<ret(__VA_ARGS__)> name = [&](__VA_ARGS__)
inline void Debug_Print(string Debug_Message) { cerr << "\n" + Debug_Message + "\n"; }
} // namespace DEBUGS
using namespace DEBUGS;
#pragma endregion DEBUGS
#pragma region BITS
namespace BITS {
template <class T>
inline T lowbit(T x) { return x & (-x); }
template <class T>
inline T highbit(T x) { return (T)(log2(x) + 1); }
template <class T>
inline T Pop_Count(T x) { return __builtin_popcount(x); }
} // namespace BITS
using namespace BITS;
#pragma endregion BITS
inline void solve(int Task_Id);
} // namespace TANGYIXIAO
using namespace TANGYIXIAO;
#pragma endregion TANGYIXIAO
#pragma region MAIN
signed main(int argc, char *argv[]) {
#ifdef TIME_COUNT
    Start_Time_Count();
#endif
    Init_IO();
#if JUDGE == 1
    Judge_File(FILE_NAME);
#elif JUDGE == 2
    Local_File(FILE_NAME, FILE_IDX);
#else
#endif
    int T = 1;
#ifdef MULTIPLE_TEST
    cin >> T;
#endif
    for (int Tasks_Id = 1; Tasks_Id <= T; Tasks_Id++) {
        solve(Tasks_Id);
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
const int MAXN = 1000005;

int n, m;
int a[MAXN], pre[MAXN], last[MAXN];

struct Node {
    int l, r;
    int val;
    int st;
    bool operator<(const Node &o) const { return l < o.l; }
};
set<Node> odt;

auto split(int pos) {
    if (pos > n)
        return odt.end();
    auto it = odt.lower_bound({pos, 0, 0, 0});
    if (it != odt.end() && it->l == pos)
        return it;
    --it;
    int L = it->l, R = it->r, val = it->val, st = it->st;
    odt.erase(it);
    odt.insert({L, pos - 1, val, st});
    return odt.insert({pos, R, val, st}).first;
}

struct Event {
    int R;
    int delta;
    int id;
    bool isMod;
};
vector<Event> events[MAXN];

void add_rect(int L1, int L2, int R1, int R2) {
    if (L1 > L2 || R1 > R2)
        return;
    events[L1].push_back({R1, 1, 0, true});
    events[L1].push_back({R2 + 1, -1, 0, true});
    events[L2 + 1].push_back({R1, -1, 0, true});
    events[L2 + 1].push_back({R2 + 1, 1, 0, true});
}

void try_merge(set<Node>::iterator it) {
    if (it == odt.end())
        return;

    auto nxt = next(it);
    if (nxt != odt.end() && nxt->val == it->val && nxt->st == it->st) {
        Node merged = {it->l, nxt->r, it->val, it->st};
        odt.erase(it);
        odt.erase(nxt);
        it = odt.insert(merged).first;
    }

    if (it != odt.begin()) {
        auto prv = prev(it);
        if (prv->val == it->val && prv->st == it->st) {
            Node merged = {prv->l, it->r, it->val, it->st};
            odt.erase(prv);
            odt.erase(it);
            odt.insert(merged);
        }
    }
}

void flip(int ql, int qr, int cur_R) {
    if (ql > qr)
        return;
    auto itr = split(qr + 1);
    auto itl = split(ql);
    vector<Node> newNodes;
    for (auto it = itl; it != itr; ++it) {
        int L = it->l, R = it->r, val = it->val, st = it->st;
        if (val == 1 && st <= cur_R - 1) {
            add_rect(L, R, st, cur_R - 1);
        }
        newNodes.push_back({L, R, val ^ 1, cur_R});
    }
    odt.erase(itl, itr);
    for (auto &nd : newNodes) {
        auto it = odt.insert(nd).first;
        try_merge(it);
    }
}

long long bit[MAXN];
void bit_add(int idx, int val) {
    for (; idx <= n; idx += idx & -idx)
        bit[idx] += val;
}
long long bit_query(int idx) {
    long long res = 0;
    for (; idx > 0; idx -= idx & -idx)
        res += bit[idx];
    return res;
}

long long ans[MAXN];

inline void solve(int Task_Id) {

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = last[a[i]];
        last[a[i]] = i;
    }
    cin >> m;

    for (int R = 1; R <= n; ++R) {

        odt.insert({R, R, 0, R});
        auto it = odt.lower_bound({R, 0, 0, 0});
        try_merge(it);

        int ql = pre[R] + 1, qr = R;
        flip(ql, qr, R);
    }

    for (auto &nd : odt) {
        if (nd.val == 1 && nd.st <= n) {
            add_rect(nd.l, nd.r, nd.st, n);
        }
    }

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;

        if (l - 1 >= 1) {
            events[l - 1].push_back({r, -1, i, false});
            events[l - 1].push_back({l - 1, 1, i, false});
        } else {
        }
        events[r].push_back({r, 1, i, false});
        if (l - 1 >= 1)
            events[r].push_back({l - 1, -1, i, false});
    }

    for (int L = 1; L <= n; ++L) {

        for (auto &ev : events[L]) {
            if (ev.isMod) {
                bit_add(ev.R, ev.delta);
            }
        }

        for (auto &ev : events[L]) {
            if (!ev.isMod) {
                ans[ev.id] += ev.delta * bit_query(ev.R);
            }
        }
    }

    for (auto &ev : events[0]) {
        if (!ev.isMod) {
            ans[ev.id] += ev.delta * bit_query(ev.R);
        }
    }

    for (int i = 0; i < m; ++i)
        cout << ans[i] << "\n";

    return;
}
} // namespace TANGYIXIAO
