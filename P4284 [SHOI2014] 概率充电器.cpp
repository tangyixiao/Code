
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
#pragma region PREPROCESSOR
#pragma region INCLUDES
#ifdef TESTLIB
#include <testlib.h> // 自定义测试库
#endif

#ifdef BITS_NOT_ALLOWED

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert> // 断言支持 (assert)
#endif
#include <cctype>  // 字符处理函数 (isalpha, toupper 等)
#include <cfloat>  // 浮点数类型极限 (FLT_MAX, DBL_MIN 等)
#include <climits> // 整数类型极限 (INT_MAX, LONG_MIN 等)
#include <csetjmp> // 非局部跳转 (setjmp, longjmp)
#include <cstdarg> // 可变参数处理 (va_list, va_start 等)
#include <cstddef> // 基础类型定义 (size_t, nullptr_t, offsetof)
#include <cstdlib> // 通用工具 (malloc, exit, atoi, rand 等)

#if __cplusplus >= 201103L
#include <cstdint> // 定长整数类型 (int32_t, uint64_t 等)
#if __cplusplus < 201703L
#include <ciso646> // 替代操作符的宏 (and, or, not) [C++17 移除]
#endif
#endif

// C++
#include <algorithm>  // 通用算法 (sort, find, for_each 等)
#include <bitset>     // 固定大小位集 (bitset)
#include <functional> // 函数对象、绑定器 (function, bind, plus 等)
#include <iterator>   // 迭代器定义与操作 (iterator_traits, begin, end)
#include <limits>     // 数值类型的极限 (numeric_limits)
#include <memory>     // 智能指针、内存管理工具 (unique_ptr, shared_ptr, allocator)
#include <new>        // 动态内存管理 (operator new, bad_alloc)
#include <numeric>    // 数值算法 (accumulate, iota, gcd 等)
#include <typeinfo>   // 运行时类型信息 (typeid, type_info)
#include <utility>    // 实用组件 (pair, move, forward, swap)

#if __cplusplus >= 201103L
#include <array>            // 固定大小容器 (array)
#include <atomic>           // 原子操作 (atomic<T>, memory_order)
#include <initializer_list> // 初始化列表支持 (initializer_list)
#include <ratio>            // 编译期有理数 (ratio, 用于 chrono)
#include <scoped_allocator> // 多级分配器 (scoped_allocator_adaptor)
#include <tuple>            // 元组 (tuple)
#include <type_traits>      // 类型特性 (is_integral, enable_if, decay)
#include <typeindex>        // type_info 的包装 (type_index)

#endif

#if __cplusplus >= 201402L
// C++14 新增头文件在此处暂无
#endif

#if __cplusplus >= 201703L
#include <any> // 可存储任意类型的对象 (any)
// #include <execution> // 并行算法策略 (execution policy) [需 TBB，默认不包含]
#include <optional>    // 可能包含值的对象 (optional)
#include <string_view> // 字符串视图 (string_view)
#include <variant>     // 类型安全的联合 (variant)

#endif

#if __cplusplus >= 202002L
#include <bit>             // 位操作函数 (bit_cast, popcount, endian)
#include <compare>         // 三路比较运算符支持 (strong_ordering 等)
#include <concepts>        // 概念 (integral, movable, invocable 等)
#include <numbers>         // 数学常数 (pi, e, sqrt2)
#include <ranges>          // 范围库 (views, ranges::sort 等)
#include <source_location> // 源代码位置信息 (source_location)
#include <span>            // 连续序列视图 (span)
#include <version>         // 特性测试宏 (__cpp_lib_*)

#if __cpp_impl_coroutine
#include <coroutine> // 协程支持 (coroutine_handle, awaitable)
#endif
#endif

#if __cplusplus > 202002L
#include <expected>    // 预期值或错误 (expected<T, E>)
#include <stdatomic.h> // C 风格原子操作 (atomic_int, atomic_load)
#endif

#if _GLIBCXX_HOSTED
// C (完整版)
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert> // 断言支持
#endif
#include <cctype>  // 字符处理函数
#include <cerrno>  // 错误码 (errno)
#include <cfloat>  // 浮点数类型极限
#include <climits> // 整数类型极限
#include <clocale> // 本地化设置 (setlocale, lconv)
#include <cmath>   // 数学函数 (sin, sqrt, pow)
#include <csetjmp> // 非局部跳转
#include <csignal> // 信号处理 (signal, raise)
#include <cstdarg> // 可变参数处理
#include <cstddef> // 基础类型定义
#include <cstdio>  // 标准 I/O (printf, FILE, fopen)
#include <cstdlib> // 通用工具
#include <cstring> // 字符串操作 (strcpy, memcpy)
#include <ctime>   // 时间和日期 (time, clock, tm)
#include <cwchar>  // 宽字符处理 (wchar_t, wcslen)
#include <cwctype> // 宽字符分类 (iswdigit, towupper)

#if __cplusplus >= 201103L
#include <cfenv>     // 浮点环境 (fenv_t, fegetround)
#include <cinttypes> // 格式化宏 for inttypes (PRIu64 等)
#include <cstdint>   // 定长整数类型
#include <cuchar>    // Unicode 字符转换 (mbrtoc16, c16rtomb)
#if __cplusplus < 201703L
#include <ccomplex>  // 复数宏 (complex) [C++17 废弃]
#include <cstdalign> // 对齐宏 (alignas) [C++17 废弃]
#include <cstdbool>  // 布尔宏 (bool, true, false) [C++17 废弃]
#include <ctgmath>   // 泛型数学 (tgmath.h) [C++17 废弃]
#endif
#endif

// C++
#include <complex>    // 复数 (complex)
#include <deque>      // 双端队列 (deque)
#include <exception>  // 异常处理 (exception, bad_exception)
#include <fstream>    // 文件流 (ifstream, ofstream)
#include <functional> // 函数对象、绑定器
#include <iomanip>    // I/O 操纵符 (setw, setprecision)
#include <ios>        // I/O 基础 (ios_base, ios)
#include <iosfwd>     // I/O 前向声明 (istream, ostream 等)
#include <iostream>   // 标准 I/O 流 (cin, cout, cerr)
#include <istream>    // 输入流 (istream)
#include <iterator>   // 迭代器定义与操作
#include <limits>     // 数值类型的极限
#include <list>       // 双向链表 (list)
#include <locale>     // 本地化 (locale, facet)
#include <map>        // 关联容器 map (map, multimap)
#include <memory>     // 智能指针、内存管理工具
#include <new>        // 动态内存管理
#include <numeric>    // 数值算法
#include <ostream>    // 输出流 (ostream)
#include <queue>      // 队列 (queue, priority_queue)
#include <set>        // 集合 set (set, multiset)
#include <sstream>    // 字符串流 (stringstream)
#include <stack>      // 栈 (stack)
#include <stdexcept>  // 标准异常 (logic_error, runtime_error)
#include <streambuf>  // 流缓冲区 (streambuf)
#include <string>     // 字符串 (string)
#include <typeinfo>   // 运行时类型信息
#include <utility>    // 实用组件
#include <valarray>   // 数值数组 (valarray)
#include <vector>     // 动态数组 (vector)

#if __cplusplus >= 201103L
#include <array>              // 固定大小容器
#include <atomic>             // 原子操作
#include <chrono>             // 时间工具 (duration, time_point, clock)
#include <codecvt>            // 编码转换 (codecvt) [C++17 弃用]
#include <condition_variable> // 条件变量 (condition_variable)
#include <forward_list>       // 单向链表 (forward_list)
#include <future>             // 异步任务 (future, promise, async)
#include <initializer_list>   // 初始化列表支持
#include <mutex>              // 互斥量 (mutex, lock_guard)
#include <random>             // 随机数生成 (mt19937, uniform_int_distribution)
#include <ratio>              // 编译期有理数
#include <regex>              // 正则表达式 (regex, smatch)
#include <scoped_allocator>   // 多级分配器
#include <system_error>       // 系统错误码 (error_code, error_category)
#include <thread>             // 线程 (thread, this_thread)
#include <tuple>              // 元组
#include <type_traits>        // 类型特性
#include <typeindex>          // type_info 包装
#include <unordered_map>      // 无序关联容器 (unordered_map, unordered_multimap)
#include <unordered_set>      // 无序集合 (unordered_set, unordered_multiset)

#endif

#if __cplusplus >= 201402L
#include <shared_mutex> // 共享互斥量 (shared_mutex, shared_lock)
#endif

#if __cplusplus >= 201703L
#include <any>      // 可存储任意类型的对象
#include <charconv> // 字符与数值转换 (from_chars, to_chars)
// #include <execution>         // 并行算法策略 [需 TBB，默认不包含]
#include <filesystem>      // 文件系统库 (path, directory_entry)
#include <memory_resource> // 多态内存资源 (pmr::memory_resource)
#include <optional>        // 可能包含值的对象
#include <variant>         // 类型安全的联合

#endif

#if __cplusplus >= 202002L
#include <barrier>         // 屏障 (barrier)
#include <bit>             // 位操作函数
#include <compare>         // 三路比较运算符支持
#include <concepts>        // 概念
#include <format>          // 格式化字符串 (format)
#include <latch>           // 闩 (latch)
#include <numbers>         // 数学常数
#include <ranges>          // 范围库
#include <semaphore>       // 信号量 (counting_semaphore, binary_semaphore)
#include <source_location> // 源代码位置信息
#include <span>            // 连续序列视图
#include <stop_token>      // 停止令牌 (stop_token, stop_source)
#include <syncstream>      // 同步输出流 (osyncstream)
#include <version>         // 特性测试宏

#endif

#if __cplusplus > 202002L
#include <expected>    // 预期值或错误
#include <flat_map>    // 扁平 map (flat_map, flat_multimap)
#include <flat_set>    // 扁平 set (flat_set, flat_multiset)
#include <generator>   // 协程生成器 (generator)
#include <print>       // 格式化打印 (print, println)
#include <spanstream>  // span 流 (spanstream, ispanstream)
#include <stacktrace>  // 堆栈跟踪 (stacktrace, stacktrace_entry)
#include <stdatomic.h> // C 风格原子操作
#include <stdfloat>    // 扩展浮点类型 (float16_t, float128_t 等)
#endif

#if __cplusplus > 202302L
#include <stdbit.h>      // C 风格位操作 (stdc_bit_ceil)
#include <stdckdint.h>   // 检查整型运算溢出 (ckd_add, ckd_mul)
#include <text_encoding> // 文本编码信息 (text_encoding)

#endif

#endif // HOSTED

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
#pragma endregion INCLUDES

#pragma region TANGYIXIAO
namespace TANGYIXIAO {
namespace IO {
inline void Init_IO() { cin.tie(0)->sync_with_stdio(false); }
namespace FILE_IO {
const string Insuffix = ".in", Outsuffix = ".out", Anssuffix = ".ans";
inline void Judge_File(string File_Name) { freopen((File_Name + Insuffix).c_str(), "r", stdin), freopen((File_Name + Outsuffix).c_str(), "w", stdout); }
inline void Local_File(string File_Name, int File_Idx) { freopen((File_Name + to_string(File_Idx) + Insuffix).c_str(), "r", stdin), freopen((File_Name + to_string(File_Idx) + Outsuffix).c_str(), "w", stdout); }
} // namespace FILE_IO
using namespace FILE_IO;
namespace INT128_IO{
// clang-format off
istream&operator>>(istream&is,__int128&x){string s;is>>s;bool neg=false;x=0;for(char c:s){if(c=='-')neg=true;else x=x*10+(c-'0');}if(neg)x=-x;return is;}
ostream&operator<<(ostream&os,__int128 x){if(x==0)os<<0;else{string s,t;if(x<0)x=-x,t="-";while(x)s.push_back('0'+x%10),x/=10;reverse(s.begin(),s.end());os<<t<<s;}return os;}
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
inline void solve(int Task_Id) {
    int n;
    cin >> n;

    vector<vector<pair<int, double>>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, p;
        cin >> a >> b >> p;
        double prob = p / 100.0;
        adj[a].emplace_back(b, prob);
        adj[b].emplace_back(a, prob);
    }

    vector<double> q(n + 1);
    for (int i = 1; i <= n; ++i) {
        int qi;
        cin >> qi;
        q[i] = qi / 100.0;
    }

    vector<int> parent(n + 1, 0);
    vector<vector<pair<int, double>>> children(n + 1); // (child, edge_prob)

    // 第一次DFS (后序遍历) 计算 down
    vector<double> down(n + 1, 0.0);
    struct State {
        int id;
        int state; // 0: 未处理子节点, 1: 已处理子节点
    };
    stack<State> st;
    st.push({1, 0});
    parent[1] = 0;

    while (!st.empty()) {
        State &cur = st.top();
        int u = cur.id;
        if (cur.state == 0) {
            cur.state = 1;
            for (auto &[v, p] : adj[u]) {
                if (v == parent[u])
                    continue;
                parent[v] = u;
                children[u].emplace_back(v, p);
                st.push({v, 0});
            }
        } else {
            // 计算 down[u]
            double prod = 1.0;
            for (auto &[v, p] : children[u]) {
                prod *= (1.0 - down[v] * p);
            }
            down[u] = 1.0 - (1.0 - q[u]) * prod;
            st.pop();
        }
    }

    // 第二次DFS (前序遍历) 计算 up
    vector<double> up(n + 1, 0.0);
    stack<int> st2;
    st2.push(1);
    while (!st2.empty()) {
        int u = st2.top();
        st2.pop();
        int k = children[u].size();
        if (k == 0)
            continue;

        // 计算前缀积和后缀积
        vector<double> pre(k + 1, 1.0), suf(k + 1, 1.0);
        for (int i = 0; i < k; ++i) {
            double fac = 1.0 - down[children[u][i].first] * children[u][i].second;
            pre[i + 1] = pre[i] * fac;
        }
        for (int i = k - 1; i >= 0; --i) {
            double fac = 1.0 - down[children[u][i].first] * children[u][i].second;
            suf[i] = suf[i + 1] * fac;
        }

        for (int i = 0; i < k; ++i) {
            int v = children[u][i].first;
            double p_edge = children[u][i].second;
            double prob_exclude = (1.0 - q[u]) * (1.0 - up[u]) * pre[i] * suf[i + 1];
            up[v] = p_edge * (1.0 - prob_exclude);
            st2.push(v);
        }
    }

    // 计算期望
    double ans = 0.0;
    for (int i = 1; i <= n; ++i) {
        ans += 1.0 - (1.0 - down[i]) * (1.0 - up[i]);
    }
    cout << fixed << setprecision(6) << ans << '\n';
    return;
}
} // namespace TANGYIXIAO
