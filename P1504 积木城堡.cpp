
/*
Copyright (C) 2026 TangYixiao
*/

#define JUDGE 0
#define FILE_IDX 1

#define DEBUG
#define TIME_COUNT
#define FILE_NAME ""
#define TEMPLATES template <class T> \
inline T

/*



#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ios>
#include <iosfwd>
#include <istream>
#include <ostream>
#include <streambuf>

#include <string>
#include <cctype>
#include <cwctype>
#include <cstring>
#include <cwchar>
#include <regex>

#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <array>
#include <forward_list>

#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <memory>

#include <cmath>
#include <complex>
#include <valarray>
#include <random>
#include <ratio>
#include <cfenv>
#include <cinttypes>
#include <cstdint>
#include <limits>

#include <utility>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <typeindex>
#include <initializer_list>
#include <optional>
#include <variant>
#include <any>

#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <atomic>

#include <chrono>
#include <ctime>

#include <locale>
#include <codecvt>

#include <stdexcept>
#include <exception>
#include <system_error>

#include <cassert>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <cstdarg>
#include <cstdbool>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <ciso646>
*/
#include <bits/stdc++.h>
using namespace std;
/*
#include <bits/extc++.h>
using namespace __gnu_pbds;
*/

/*
#include<testlib.h>
*/
namespace TANGYIXIAO {
namespace IO {
inline void Init_IO() { cin.tie(0)->sync_with_stdio(false); }
} // namespace IO
using namespace IO;
namespace FILE_IO {
const string Insuffix = ".in", Outsuffix = ".out", Anssuffix = ".ans";
inline void Judge_File(string File_Name) { freopen((File_Name + Insuffix).c_str(), "r", stdin), freopen((File_Name + Outsuffix).c_str(), "w", stdout); }
inline void Local_File(string File_Name, int File_Idx) { freopen((File_Name + to_string(File_Idx) + Insuffix).c_str(), "r", stdin), freopen((File_Name + to_string(File_Idx) + Outsuffix).c_str(), "w", stdout); }
} // namespace FILE_IO
using namespace FILE_IO;
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
TEMPLATES lowbit(T x) { return x & (-x); }
TEMPLATES highbit(T x) { return (T)(log2(x) + 1); }
TEMPLATES Pop_Count(T x) { return __builtin_popcount(x); }
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

const int MAXH = 10000;
inline void solve(int Task_Id) {
    int n;
    cin >> n;
    bitset<MAXH + 1> ans;
    ans.set();
    bool first = true;

    for (int i = 0; i < n; ++i) {
        bitset<MAXH + 1> dp;
        dp[0] = 1;
        int h;
        while (cin >> h && h != -1) {
            if (h > 0) {
                dp |= dp << h;
            }
        }

        if (first) {
            ans = dp;
            first = false;
        } else {
            ans &= dp;
        }
    }

    int result = 0;
    for (int i = MAXH; i >= 0; --i) {
        if (ans[i]) {
            result = i;
            break;
        }
    }
    cout << result << '\n';
    return;
}
} // namespace TANGYIXIAO
