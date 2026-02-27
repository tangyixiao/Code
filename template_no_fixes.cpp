#define JUDGE 0
#define FILE_IDX 1

#define FILE_NAME ""

#ifdef BITS_NOT_ALLOWED
#ifdef TESTLIB
#include <testlib.h>
#endif
#include <fstream>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <streambuf>

#include <cctype>
#include <cstring>
#include <cwchar>
#include <cwctype>
#include <regex>
#include <string>

#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <algorithm>
#include <functional>
#include <iterator>
#include <memory>
#include <numeric>

#include <cfenv>
#include <cinttypes>
#include <cmath>
#include <complex>
#include <cstdint>
#include <limits>
#include <random>
#include <ratio>
#include <valarray>

#include <any>
#include <initializer_list>
#include <optional>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <utility>
#include <variant>

#include <atomic>
#include <condition_variable>
#include <future>
#include <mutex>
#include <thread>

#include <chrono>
#include <ctime>

#include <codecvt>
#include <locale>

#include <exception>
#include <stdexcept>
#include <system_error>

#include <cassert>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <cstdarg>
#include <cstdbool>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cwchar>
#include <cwctype>

#else
#include <bits/stdc++.h>
#endif
using namespace std;

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
namespace TANGYIXIAO {
namespace IO {
inline void Init_IO() { cin.tie(0)->sync_with_stdio(false); }
namespace FILE_IO {
const string Insuffix = ".in", Outsuffix = ".out", Anssuffix = ".ans";
inline void Judge_File(string File_Name) { freopen((File_Name + Insuffix).c_str(), "r", stdin), freopen((File_Name + Outsuffix).c_str(), "w", stdout); }
inline void Local_File(string File_Name, int File_Idx) { freopen((File_Name + to_string(File_Idx) + Insuffix).c_str(), "r", stdin), freopen((File_Name + to_string(File_Idx) + Outsuffix).c_str(), "w", stdout); }
} // namespace FILE_IO
using namespace FILE_IO;
namespace INT128_IO {
// clang-format off
istream &operator>>(istream &is, i128 &x) { string s; is >> s; bool neg = false; x = 0; for (char c : s) { if (c == '-') neg = true; else x = x * 10 + (c - '0'); } if (neg) x = -x; return is; }
ostream &operator<<(ostream &os, i128 x) { if (x == 0) os << 0; else { string s, t; if (x < 0) x = -x, t = "-"; while (x) s.push_back('0' + x % 10), x /= 10; reverse(s.begin(), s.end()); os << t << s; } return os; }
// clang-format on
} // namespace INT128_IO
using namespace INT128_IO;
} // namespace IO
using namespace IO;
namespace TIME {
clock_t Start_Time, End_Time;
inline void Start_Time_Count() { Start_Time = clock(); }
inline void End_Time_Count() { End_Time = clock(); }
inline double Time_Count() { return (double)(End_Time - Start_Time) / CLOCKS_PER_SEC; }
inline void Print_Time_Count(string Programe_Name) { cerr << fixed << setprecision(4) << "\n" + Programe_Name + " Time: " << Time_Count() << "s\n"; }
} // namespace TIME
using namespace TIME;
namespace DEBUGS {
inline void Debug_Print(string Debug_Message) { cerr << "\n" + Debug_Message + "\n"; }
} // namespace DEBUGS
using namespace DEBUGS;
namespace BITS {
template <class T>
inline T lowbit(T x) { return x & (-x); }
template <class T>
inline T highbit(T x) { return (T)(log2(x) + 1); }
template <class T>
inline T Pop_Count(T x) { return __builtin_popcount(x); }
} // namespace BITS
using namespace BITS;
inline void solve(int Task_Id);
} // namespace TANGYIXIAO
using namespace TANGYIXIAO;
signed main() {
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
namespace TANGYIXIAO {
inline void solve(int Task_Id) {

    return;
}
} // namespace TANGYIXIAO
