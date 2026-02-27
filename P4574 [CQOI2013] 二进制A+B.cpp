

/*
Copyright (C) 2026 TangYixiao
*/

#define JUDGE 0    // 0 for online judge, 1 for judge file , 2 for local file
#define FILE_IDX 1 // the index of the file in the local file system
// #define MULTIPLE_TEST
#define DEBUG
#define TIME_COUNT
#define FILE_NAME ""
#define TEMPLATES template <class T> \
inline T

/*

// #include<testlib.h> // 自定义测试库

#include <iostream>      // 标准输入输出流
#include <iomanip>       // 输入输出流格式化
#include <fstream>       // 文件流
#include <sstream>       // 字符串流
#include <ios>           // 输入输出流基础
#include <iosfwd>        // 输入输出流前置声明
#include <istream>       // 输入流
#include <ostream>       // 输出流
#include <streambuf>     // 流缓冲区

#include <string>        // 字符串类
#include <cctype>        // 字符处理函数
#include <cwctype>       // 宽字符处理
#include <cstring>       // C风格字符串
#include <cwchar>        // 宽字符支持
#include <regex>         // 正则表达式

#include <vector>        // 动态数组
#include <list>          // 双向链表
#include <deque>         // 双端队列
#include <queue>         // 队列（包括priority_queue）
#include <stack>         // 栈
#include <map>           // 映射（有序）
#include <set>           // 集合（有序）
#include <unordered_map> // 哈希映射
#include <unordered_set> // 哈希集合
#include <bitset>        // 位集
#include <array>         // 固定大小数组
#include <forward_list>  // 单向链表

#include <algorithm>     // 算法库
#include <numeric>       // 数值算法
#include <functional>    // 函数对象
#include <iterator>      // 迭代器
#include <memory>        // 智能指针

#include <cmath>         // 数学函数
#include <complex>       // 复数
#include <valarray>      // 数值数组
#include <random>        // 随机数
#include <ratio>         // 有理数
#include <cfenv>         // 浮点环境
#include <cinttypes>     // 整数类型
#include <cstdint>       // 固定宽度整数
#include <limits>        // 数值极限

#include <utility>       // 工具类（pair等）
#include <tuple>         // 元组
#include <type_traits>   // 类型特性
#include <typeinfo>      // 类型信息
#include <typeindex>     // 类型索引
#include <initializer_list> // 初始化列表
#include <optional>      // 可选值（C++17）
#include <variant>       // 变体（C++17）
#include <any>           // 任意类型（C++17）

#include <thread>        // 线程
#include <mutex>         // 互斥锁
#include <condition_variable> // 条件变量
#include <future>        // 异步操作
#include <atomic>        // 原子操作

#include <chrono>        // 时间库
#include <ctime>         // C时间函数

#include <locale>        // 本地化
#include <codecvt>       // 编码转换

#include <stdexcept>     // 标准异常
#include <exception>     // 异常基类
#include <system_error>  // 系统错误

#include <cassert>       // 断言
#include <cerrno>        // 错误码
#include <cfloat>        // 浮点数特性
#include <climits>       // 整数极限
#include <cstdarg>       // 可变参数
#include <cstdbool>      // C布尔类型
#include <cstdlib>       // C标准库
#include <cstdio>        // C输入输出
#include <ctime>         // C时间函数
#include <cwchar>        // 宽字符
#include <cwctype>       // 宽字符分类
#include <ciso646>       // 备选运算符宏
*/
#include <bits/stdc++.h>
using namespace std;
/*
#include <bits/extc++.h>
using namespace __gnu_pbds;
*/

/*
#include<testlib.h> // 自定义测试库
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

int Digit(int x) {
    int re = 0;
    while (x)
        ++re, x >>= 1;
    return re;
}
int Count(int x) {
    int re = 0;
    while (x)
        x ^= x & -x, ++re;
    return re;
}
inline void solve(int Task_Id) {
    int x, y, z, limit, ans;
    cin >> x >> y >> z;
    limit = max(max(Digit(x), Digit(y)), Digit(z));
    x = Count(x);
    y = Count(y);
    z = Count(z);
    if (x < y)
        swap(x, y);
    if (z <= y)
        ans = ((1 << x) - 1) + ((1 << z) - 1 | ((1 << y - z) - 1 << x));
    else if (z <= x)
        ans = ((1 << x) - 1) + ((1 << y) - 1 << z - y);
    else if (z <= x + y)
        ans = ((1 << x) - 1 << z - x) + ((1 << z - x) - 1 | ((1 << x + y - z) - 1 << z + z - x - y));
    else
        ans = -1;
    if (Digit(ans) > limit)
        ans = -1;
    cout << ans << endl;
    return;
}

} // namespace TANGYIXIAO
