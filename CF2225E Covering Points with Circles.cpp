
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
int floor_div(int a, int b) {
    int q = a / b;
    int r = a % b;
    if (r != 0 && ((a < 0) ^ (b < 0)))
        --q;
    return q;
}

int round_div(int a, int b) {
    if (a >= 0)
        return (a + b / 2) / b;
    else
        return (a - b / 2) / b;
}

pair<int, vector<pair<int, int>>> check_offset(
    int off_x, int off_y,
    const vector<pair<int, int>> &points,
    int r, int dx, int dy) {
    int n = points.size();
    vector<bool> covered(n, false);
    int covered_cnt = 0;
    vector<pair<int, int>> cents;

    for (int i = 0; i < n; ++i) {
        int px = points[i].first;
        int py = points[i].second;
        int py_prime = py - off_y;

        int i1 = floor_div(py_prime, dy);

        for (int i_row = i1; i_row <= i1 + 1; ++i_row) {
            int cy = off_y + i_row * dy;
            if (abs(cy - py) > r)
                continue;

            int x_base = off_x + (i_row % 2 == 0 ? 0 : r);
            int dx_p = px - x_base;

            int j = round_div(dx_p, dx);

            for (int dj = -1; dj <= 1; ++dj) {
                int jj = j + dj;
                int cx = x_base + jj * dx;
                int64_t dist2 = (int64_t)(cx - px) * (cx - px) + (int64_t)(cy - py) * (cy - py);
                if (dist2 <= (int64_t)r * r) {
                    if (!covered[i]) {
                        covered[i] = true;
                        ++covered_cnt;
                    }
                    cents.emplace_back(cx, cy);
                }
            }
        }
    }

    sort(cents.begin(), cents.end());
    cents.erase(unique(cents.begin(), cents.end()), cents.end());

    return {covered_cnt, cents};
}

void greedy_add(
    const vector<pair<int, int>> &points,
    int r,
    vector<pair<int, int>> &centers,
    vector<bool> &covered,
    int &covered_cnt,
    int target,
    mt19937 &rng) {
    int n = points.size();
    vector<int> uncovered_idx;
    for (int i = 0; i < n; ++i)
        if (!covered[i])
            uncovered_idx.push_back(i);

    while (covered_cnt < target) {
        int best_cnt = 0;
        int best_cx = 0, best_cy = 0;

        vector<int> candidates = uncovered_idx;
        if (candidates.size() > 500) {
            shuffle(candidates.begin(), candidates.end(), rng);
            candidates.resize(500);
        }

        for (int idx : candidates) {
            int px = points[idx].first;
            int py = points[idx].second;

            int cx = px, cy = py;
            bool conflict = false;
            for (auto &c : centers) {
                int64_t d2 = (int64_t)(c.first - cx) * (c.first - cx) + (int64_t)(c.second - cy) * (c.second - cy);
                if (d2 < 4LL * r * r) {
                    conflict = true;
                    break;
                }
            }

            if (conflict) {

                for (int dx = -r / 2; dx <= r / 2; dx += r / 4) {
                    for (int dy = -r / 2; dy <= r / 2; dy += r / 4) {
                        int ncx = px + dx;
                        int ncy = py + dy;
                        bool conf = false;
                        for (auto &c : centers) {
                            int64_t d2 = (int64_t)(c.first - ncx) * (c.first - ncx) + (int64_t)(c.second - ncy) * (c.second - ncy);
                            if (d2 < 4LL * r * r) {
                                conf = true;
                                break;
                            }
                        }
                        if (!conf) {
                            int cnt = 0;
                            for (int u : uncovered_idx) {
                                int ux = points[u].first, uy = points[u].second;
                                int64_t d2 = (int64_t)(ux - ncx) * (ux - ncx) + (int64_t)(uy - ncy) * (uy - ncy);
                                if (d2 <= (int64_t)r * r)
                                    ++cnt;
                            }
                            if (cnt > best_cnt) {
                                best_cnt = cnt;
                                best_cx = ncx;
                                best_cy = ncy;
                            }
                        }
                    }
                }
                continue;
            }

            int cnt = 0;
            for (int u : uncovered_idx) {
                int ux = points[u].first, uy = points[u].second;
                int64_t d2 = (int64_t)(ux - cx) * (ux - cx) + (int64_t)(uy - cy) * (uy - cy);
                if (d2 <= (int64_t)r * r)
                    ++cnt;
            }
            if (cnt > best_cnt) {
                best_cnt = cnt;
                best_cx = cx;
                best_cy = cy;
            }
        }

        if (best_cnt == 0)
            break;

        centers.emplace_back(best_cx, best_cy);

        vector<int> new_uncovered;
        for (int u : uncovered_idx) {
            int ux = points[u].first, uy = points[u].second;
            int64_t d2 = (int64_t)(ux - best_cx) * (ux - best_cx) + (int64_t)(uy - best_cy) * (uy - best_cy);
            if (d2 <= (int64_t)r * r) {
                covered[u] = true;
                ++covered_cnt;
            } else {
                new_uncovered.push_back(u);
            }
        }
        uncovered_idx.swap(new_uncovered);
    }
}

inline void solve(int Task_Id) {

    int n, r;
    cin >> n >> r;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    int dx = 2 * r;
    int dy = (int)ceil(sqrt(3.0) * r + 1e-9);
    int period_y = 2 * dy;

    int target = (int)ceil(0.89 * n);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist_x(0, dx - 1);
    uniform_int_distribution<int> dist_y(0, period_y - 1);

    int best_covered = 0;
    vector<pair<int, int>> best_centers;
    vector<bool> best_covered_flags;

    const int MAX_ATTEMPTS = 800;

    for (int attempt = 0; attempt < MAX_ATTEMPTS; ++attempt) {
        int off_x = dist_x(rng);
        int off_y = dist_y(rng);
        auto [cov, cents] = check_offset(off_x, off_y, points, r, dx, dy);
        if (cov > best_covered) {
            best_covered = cov;
            best_centers = move(cents);
            if (best_covered >= target)
                break;
        }
    }

    if (best_covered < target) {

        vector<bool> covered(n, false);
        int cov_cnt = 0;
        for (auto &c : best_centers) {
            for (int i = 0; i < n; ++i) {
                if (!covered[i]) {
                    int64_t d2 = (int64_t)(points[i].first - c.first) * (points[i].first - c.first) + (int64_t)(points[i].second - c.second) * (points[i].second - c.second);
                    if (d2 <= (int64_t)r * r) {
                        covered[i] = true;
                        ++cov_cnt;
                    }
                }
            }
        }
        greedy_add(points, r, best_centers, covered, cov_cnt, target, rng);
    }

    cout << best_centers.size() << '\n';
    for (auto &c : best_centers) {
        cout << c.first << ' ' << c.second << '\n';
    }

    return;
}
} // namespace TANGYIXIAO
