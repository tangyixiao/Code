
/*
Copyright (C) 2026 TangYixiao
*/

#define JUDGE 0    // 0 for online judge, 1 for judge file , 2 for local file
#define FILE_IDX 1 // the index of the file in the local file system
// #define MULTIPLE_TEST
// #define DEBUG
// #define TIME_COUNT
#define FILE_NAME ""
// #define BITS_NOT_ALLOWED
// #define PD_DS_USED
// #define TESTLIB

#ifdef BITS_NOT_ALLOWED
#ifdef TESTLIB
#include <testlib.h> // 自定义测试库
#endif
#include <fstream>   // 文件流
#include <iomanip>   // 输入输出流格式化
#include <ios>       // 输入输出流基础
#include <iosfwd>    // 输入输出流前置声明
#include <iostream>  // 标准输入输出流
#include <istream>   // 输入流
#include <ostream>   // 输出流
#include <sstream>   // 字符串流
#include <streambuf> // 流缓冲区

#include <cctype>  // 字符处理函数
#include <cstring> // C风格字符串
#include <cwchar>  // 宽字符支持
#include <cwctype> // 宽字符处理
#include <regex>   // 正则表达式
#include <string>  // 字符串类

#include <array>         // 固定大小数组
#include <bitset>        // 位集
#include <deque>         // 双端队列
#include <forward_list>  // 单向链表
#include <list>          // 双向链表
#include <map>           // 映射（有序）
#include <queue>         // 队列（包括priority_queue）
#include <set>           // 集合（有序）
#include <stack>         // 栈
#include <unordered_map> // 哈希映射
#include <unordered_set> // 哈希集合
#include <vector>        // 动态数组

#include <algorithm>  // 算法库
#include <functional> // 函数对象
#include <iterator>   // 迭代器
#include <memory>     // 智能指针
#include <numeric>    // 数值算法

#include <cfenv>     // 浮点环境
#include <cinttypes> // 整数类型
#include <cmath>     // 数学函数
#include <complex>   // 复数
#include <cstdint>   // 固定宽度整数
#include <limits>    // 数值极限
#include <random>    // 随机数
#include <ratio>     // 有理数
#include <valarray>  // 数值数组

#include <any>              // 任意类型（C++17）
#include <initializer_list> // 初始化列表
#include <optional>         // 可选值（C++17）
#include <tuple>            // 元组
#include <type_traits>      // 类型特性
#include <typeindex>        // 类型索引
#include <typeinfo>         // 类型信息
#include <utility>          // 工具类（pair等）
#include <variant>          // 变体（C++17）

#include <atomic>             // 原子操作
#include <condition_variable> // 条件变量
#include <future>             // 异步操作
#include <mutex>              // 互斥锁
#include <thread>             // 线程

#include <chrono> // 时间库
#include <ctime>  // C时间函数

#include <codecvt> // 编码转换
#include <locale>  // 本地化

#include <exception>    // 异常基类
#include <stdexcept>    // 标准异常
#include <system_error> // 系统错误

#include <cassert>  // 断言
#include <cerrno>   // 错误码
#include <cfloat>   // 浮点数特性
#include <ciso646>  // 备选运算符宏
#include <climits>  // 整数极限
#include <cstdarg>  // 可变参数
#include <cstdbool> // C布尔类型
#include <cstdio>   // C输入输出
#include <cstdlib>  // C标准库
#include <ctime>    // C时间函数
#include <cwchar>   // 宽字符
#include <cwctype>  // 宽字符分类

#else
#include <bits/stdc++.h>
#endif
using namespace std;

/*

注意在用 priority_queue 时，可能会和 std 的冲突。

*/

#ifdef PD_DS_USED
#ifdef BITS_NOT_ALLOWED

// __gnu_pbds 常用头文件及功能注释
#include <ext/pb_ds/assoc_container.hpp>    // 关联容器：hash、tree等基类
#include <ext/pb_ds/exception.hpp>          // 异常类
#include <ext/pb_ds/hash_fn>                // 哈希函数（如直接、取模等）
#include <ext/pb_ds/hash_policy.hpp>        // 哈希策略：cc_hash_table（链地址），gp_hash_table（开放地址）
#include <ext/pb_ds/list_update_policy.hpp> // 列表更新策略（用于哈希表冲突处理）
#include <ext/pb_ds/priority_queue.hpp>     // 优先队列：pairing_heap（配对堆），binomial_heap等，支持 merge、modify
#include <ext/pb_ds/tag_and_trait.hpp>      // 标签与特性，如 rb_tree_tag 等
#include <ext/pb_ds/tree_policy.hpp>        // 树策略：实现 order_of_key 和 find_by_order
#include <ext/pb_ds/trie_policy.hpp>        // Trie 树策略（较少用）
#include <ext/rope>                         // 可持久化块状链表（属于 __gnu_cxx，但常与 pbds 一起使用）
using namespace __gnu_pbds;

#else

#include <bits/extc++.h> // 万能扩展头文件（包含大部分 pbds 和 rope）
using namespace __gnu_pbds;
#endif

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

typedef long long ll;
const int N = 50005;
struct Cow {
    ll p, c;
} cows[N];

bool cmp_c(const Cow &a, const Cow &b) {
    return a.c < b.c;
}
bool vis[N];
inline void solve(int Task_Id) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    ll m;
    cin >> n >> k >> m;
    for (int i = 0; i < n; ++i) {
        cin >> cows[i].p >> cows[i].c;
    }
    sort(cows, cows + n, cmp_c);
    ll tot = 0;
    int cnt = 0;
    priority_queue<ll, vector<ll>, greater<ll>> dif;
    int i = 0;
    for (; i < n && k > 0; ) {
        if (tot + cows[i].c <= m) {
            tot += cows[i].c;
            ++cnt;
            dif.push(cows[i].p - cows[i].c);
            vis[i] = true;
            ++i;
            --k;
        } else {
            break;
        }
    }

    if (i == n) {
        cout << cnt << "\n";
        exit(0);
    }

    if (k > 0) {
        vector<pair<ll, int>> rem;
        for (int j = i; j < n; ++j) {
            rem.emplace_back(cows[j].p, j);
        }
        sort(rem.begin(), rem.end());
        for (auto pr : rem) {
            if (tot + pr.first <= m) {
                tot += pr.first;
                ++cnt;
                vis[pr.second] = true;
            } else {
                break;
            }
        }
        cout << cnt << "\n";
        exit(0);
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> hp, hC;
    for (int j = i; j < n; ++j) {
        hp.emplace(cows[j].p, j), hC.emplace(cows[j].c, j);
    }

    for (;;) {
        ll cp = LLONG_MAX;
        for (; !hp.empty();) {
            int idx = hp.top().second;
            if (vis[idx]) {
                hp.pop();
            } else {
                cp = hp.top().first;
                break;
            }
        }

        ll cC = LLONG_MAX;
        int idxC = -1;
        for (; !hC.empty();) {
            int idx = hC.top().second;
            if (vis[idx]) {
                hC.pop();
            } else {
                cC = hC.top().first;
                idxC = idx;
                break;
            }
        }

        ll cr = LLONG_MAX;
        if (!dif.empty() && idxC != -1) {
            cr = cC + dif.top();
        }
        ll ans = min(cp, cr);
        if (ans == LLONG_MAX) {
            break;
        }
        if (tot + ans > m) {
            break;
        }
        if (ans == cp) {
            int idx = hp.top().second;
            tot += cp, ++cnt, vis[idx] = true;
            hp.pop();
        } else {
            int idx = idxC;
            tot += cr, ++cnt, vis[idx] = true;
            hC.pop();
            dif.pop();
            dif.push(cows[idx].p - cows[idx].c);
        }
    }

    cout << cnt << "\n";
    return;
}
} // namespace TANGYIXIAO
