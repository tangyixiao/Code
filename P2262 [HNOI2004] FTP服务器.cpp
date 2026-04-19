
/*
Copyright (C) 2026 TangYixiao
*/

#define PRAGMA_TYPE 0 // 0 for no pragma, 1 for Real optimize, 2 for All optimize, 3 for Compiler optimize
// #define PRAGMA_GPlusPlus_ALLOWED
#define JUDGE_TYPE 0 // 0 for online judge, 1 for judge file , 2 for local file
#define FILE_INDEX 1 // the index of the file in the local file system
// #define MULTIPLE_TEST
// #define DEBUG
// #define TIME_COUNT
#define FILE_NAME ""
// #define BITS_NOT_ALLOWED
// #define PD_DS_USED
// #define TESTLIB
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
#pragma GCC optimize("Ofast,no-stack-protector") // 实测最好，但注意浮点数优化可能会导致精度问题，慎用

#pragma GCC optimize("Ofast")
#pragma GCC target("sse3","sse2","sse")
#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC diagnostic error "-std=c++14" // 注意版本
*/
#elif PRAGMA_TYPE == 3

#pragma region PRAGMA_COMPILER
#pragma region Optimization

/*
#pragma GCC optimize("O0")                 // 对应 -O0：关闭所有优化（默认）
#pragma GCC optimize("O1")                 // 对应 -O1：基本优化，不显著增加编译时间
#pragma GCC optimize("O2")                 // 对应 -O2：推荐优化级别，启用大部分非体积换速度的优化
#pragma GCC optimize("O3")                 // 对应 -O3：激进优化，包含函数内联等，可能增大代码体积
#pragma GCC optimize("Os")                 // 对应 -Os：优化代码体积，在 -O2 基础上进一步压缩大小
#pragma GCC optimize("Ofast")              // 对应 -Ofast：无视严格标准，追求极致性能（含 -O3 和快速数学）
#pragma GCC optimize("Og")                 // 对应 -Og：调试时优化，平衡调试体验和运行性能

// 具体优化开关（可叠加，用空格分隔）
#pragma GCC optimize("unroll-loops")       // 对应 -funroll-loops：展开循环
#pragma GCC optimize("inline-functions")   // 对应 -finline-functions：内联简单函数
#pragma GCC optimize("omit-frame-pointer") // 对应 -fomit-frame-pointer：省略栈帧指针
#pragma GCC optimize("tree-vectorize")     // 对应 -ftree-vectorize：启用自动向量化
*/
#pragma endregion Optimization
#pragma region Target_Architecture
/*
#pragma GCC target("arch=native")  // 对应 -march=native：针对本机CPU优化指令集
#pragma GCC target("arch=core2")   // 对应 -march=core2：针对 Core2 架构
#pragma GCC target("tune=generic") // 对应 -mtune=generic：通用调度优化
#pragma GCC target("tune=intel")   // 对应 -mtune=intel：为 Intel CPU 优化调度
#pragma GCC target("sse2")         // 对应 -msse2：启用 SSE2 指令集
#pragma GCC target("sse4.2")       // 对应 -msse4.2：启用 SSE4.2
#pragma GCC target("avx")          // 对应 -mavx：启用 AVX 指令集
#pragma GCC target("avx2")         // 对应 -mavx2：启用 AVX2
#pragma GCC target("fma")          // 对应 -mfma：启用 FMA（融合乘加）指令
#pragma GCC target("bmi2")         // 对应 -mbmi2：启用 BMI2 指令集
#pragma GCC target("popcnt")       // 对应 -mpopcnt：启用 POPCNT 指令
#pragma GCC target("crc32")        // 对应 -mcrc32：启用 CRC32 指令
#pragma GCC target("no-sse")       // 对应 -mno-sse：禁用 SSE 指令集

// 嵌入式 / ARM 相关
#pragma GCC target("thumb")           // 对应 -mthumb：生成 Thumb 指令集代码
#pragma GCC target("arm")             // 对应 -marm：生成 ARM 指令集代码
#pragma GCC target("arch=armv7-a")    // 对应 -march=armv7-a
#pragma GCC target("mfpu=neon")       // 对应 -mfpu=neon：使用 NEON 向量单元
#pragma GCC target("mfloat-abi=hard") // 对应 -mfloat-abi=hard：硬件浮点 ABI
*/
#pragma endregion Target_Architecture
#pragma region Diagnostic_Warnings
/*
// 基本警告控制：忽略、警告、错误
#pragma GCC diagnostic ignored "-Wunused-variable"  // 忽略未使用变量警告
#pragma GCC diagnostic warning "-Wunused-parameter" // 将“未使用参数”作为警告（默认级别）
#pragma GCC diagnostic error "-Wformat-security"    // 将格式字符串安全问题提升为错误

// 常用警告组（部分组名可作为整体控制，但更推荐单独控制具体警告）
#pragma GCC diagnostic ignored "-Wall" // 忽略绝大部分常见警告（不推荐）
#pragma GCC diagnostic error "-Wextra" // 将 -Wextra 中的警告视为错误

// 其他常见警告
#pragma GCC diagnostic ignored "-Wconversion"        // 忽略隐式类型转换警告
#pragma GCC diagnostic ignored "-Wsign-compare"      // 忽略有符号/无符号比较警告
#pragma GCC diagnostic warning "-Wshadow"            // 变量遮蔽警告（警告级别）
#pragma GCC diagnostic error "-Wnull-dereference"    // 空指针解引用错误
#pragma GCC diagnostic error "-Wmaybe-uninitialized" // 可能未初始化变量错误

// 严格标准警告
#pragma GCC diagnostic error "-Wpedantic"   // 对应 -pedantic-errors：严格遵循标准
#pragma GCC diagnostic warning "-Wpedantic" // 对应 -pedantic：发出严格标准警告

// 保存/恢复诊断状态（用于局部临时修改）
#pragma GCC diagnostic push                        // 保存当前诊断设置
#pragma GCC diagnostic ignored "-Wunused-variable" // 临时忽略
// ... 代码 ...
#pragma GCC diagnostic pop // 恢复之前设置
*/
#pragma endregion Diagnostic_Warnings
#pragma region Visibility_Linking
/*
#pragma GCC visibility push(hidden) // 对应 -fvisibility=hidden：隐藏后续所有符号
// ... 代码（例如不希望导出的内部函数） ...
#pragma GCC visibility pop // 恢复之前的可见性设置

#pragma GCC visibility push(default) // 对应默认可见性（外部可见）
// ... 代码（需要导出的 API） ...
#pragma GCC visibility pop

// 注意：无法通过 #pragma 直接控制 -static, -shared, -l 等链接器选项
*/
#pragma endregion Visibility_Linking
#pragma region Stack Protection_Security
/*
// 使用 optimize pragma 控制栈保护（GCC 4.9+ 支持）
#pragma GCC optimize("stack-protector-strong") // 对应 -fstack-protector-strong：强栈保护
#pragma GCC optimize("no-stack-protector")     // 对应 -fno-stack-protector：禁用栈保护

// 地址消毒剂（AddressSanitizer）无法通过 #pragma 在函数级开关，需要全局 -fsanitize=address
// 但可以在函数上使用 __attribute__((no_sanitize_address))，此处不展开
*/
#pragma endregion Stack Protection_Security
#pragma region Miscellaneous_Code_Generation
/*

// 位置无关代码（PIC）不支持函数级 #pragma，但可以这样尝试（效果有限）
#pragma GCC optimize("fPIC")             // 可能无效，实际需全局 -fPIC，此处仅为示例

// 禁止异常展开（C++）
#pragma GCC optimize("no-exceptions")    // 对应 -fno-exceptions，仅在 C++ 中生效

// 禁止 RTTI（C++）
#pragma GCC optimize("no-rtti")          // 对应 -fno-rtti

// 函数内联阈值调整
#pragma GCC optimize("inline-limit=100") // 对应 --param inline-min-speedup=100（近似）
*/
#pragma endregion Miscellaneous_Code_Generation
#pragma region Pushing_Popping_Options
/*

#pragma GCC push_options   // 保存当前所有优化和目标选项
#pragma GCC optimize("O3") // 临时启用 O3
#pragma GCC target("avx2") // 临时启用 AVX2
// ... 需要高性能的代码段 ...
#pragma GCC pop_options    // 恢复之前保存的选项
*/
#pragma endregion Pushing_Popping_Options
#pragma endregion PRAGMA_COMPILER
#else
#endif
#pragma endregion PRAGMAS

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
// clang-format off
istream&operator>>(istream&is,__int128&x){string s;is>>s;bool neg=false;x=0;for(char c:s){if(c=='-')neg=true;else x=x*10+(c-'0');}if(neg)x=-x;return is;}
ostream&operator<<(ostream&os,__int128 x){if(x==0)os<<0;else{string s,t;if(x<0)x=-x,t="-";while(x)s.push_back('0'+x%10),x/=10;reverse(s.begin(),s.end());os<<t<<s;}return os;}
// clang-format on
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
// 前向声明
class Node;
struct User;

// 事件类型：传输完成事件优先于命令事件
enum EventType { TRANSFER_COMPLETE = 0,
                 COMMAND = 1 };

// 事件结构体
struct Event {
    int time;
    EventType type;
    // 命令相关
    string user;
    string cmd;
    vector<string> args;
    int order; // 仅命令事件有效，用于同时间排序
    // 传输完成相关
    string transferUserName;
    int eventId; // 用于惰性删除
    bool valid;

    // 默认构造
    Event() : time(0), type(COMMAND), order(0), eventId(-1), valid(true) {}
};

// 文件/文件夹节点
class Node {
  public:
    string name;
    bool isFolder;
    int size; // 文件大小，文件夹不使用此字段
    Node *parent;
    vector<Node *> children;
    int uploadingCount; // 仅文件夹有效：直接子节点中处于uploading状态的数量
    bool uploading;     // 仅文件有效：是否处于上传未完成状态

    Node(string n, bool folder, int sz = 0)
        : name(n), isFolder(folder), size(sz), parent(nullptr),
          uploadingCount(0), uploading(false) {}

    // 判断当前节点是否处于uploading状态
    bool isUploading() const {
        if (isFolder)
            return uploadingCount > 0;
        else
            return uploading;
    }

    // 设置文件的上传状态（仅文件调用）
    void setFileUploading(bool u) {
        if (isFolder)
            return;
        if (uploading == u)
            return;
        uploading = u;
        if (parent) {
            if (u)
                parent->addUploadingChild();
            else
                parent->removeUploadingChild();
        }
    }

    // 增加一个处于uploading状态的直接子节点（由子节点调用）
    void addUploadingChild() {
        if (!isFolder)
            return;
        uploadingCount++;
        if (uploadingCount == 1 && parent) {
            parent->addUploadingChild();
        }
    }

    // 减少一个处于uploading状态的直接子节点
    void removeUploadingChild() {
        if (!isFolder)
            return;
        uploadingCount--;
        if (uploadingCount == 0 && parent) {
            parent->removeUploadingChild();
        }
    }

    // 添加子节点
    void addChild(Node *child) {
        children.push_back(child);
        child->parent = this;
        if (child->isUploading()) {
            addUploadingChild();
        }
    }

    // 移除直接子节点（不释放内存，仅解除关系并更新状态）
    void removeChild(Node *child) {
        auto it = find(children.begin(), children.end(), child);
        if (it != children.end()) {
            // 如果子节点处于uploading状态，需要更新计数
            if (child->isUploading()) {
                if (!child->isFolder) {
                    // 文件：直接减少父节点uploading计数
                    removeUploadingChild();
                } else {
                    // 文件夹：其内部可能有多个uploading，但我们只关心它作为一个整体对父节点的影响
                    // 由于文件夹被移除，相当于一个uploading子节点消失
                    removeUploadingChild();
                }
            }
            children.erase(it);
        }
    }

    // 查找直接子节点
    Node *findChild(const string &name) {
        for (Node *child : children) {
            if (child->name == name)
                return child;
        }
        return nullptr;
    }

    // 递归计算总大小（用于下载）
    int getTotalSize() const {
        if (!isFolder)
            return size;
        int total = 0;
        for (Node *child : children) {
            if (!child->isFolder) {
                total += child->size;
            } else {
                total += child->getTotalSize();
            }
        }
        return total;
    }
};

// 用户结构
struct User {
    string name;
    int type; // 1:上传用户  2:下载用户  3:匿名用户
    enum State { IDLE,
                 UPLOADING,
                 DOWNLOADING } state;
    Node *position;
    Node *transferTarget; // 正在传输的目标节点
    int remainingSize;    // 剩余需传输字节数
    int currentCompleteEventId;

    User(string n, int t, Node *root)
        : name(n), type(t), state(IDLE), position(root),
          transferTarget(nullptr), remainingSize(0), currentCompleteEventId(-1) {}
};

// 全局服务器参数（在主函数内定义，通过引用传递）
int maxUserNumber, maxServerFlux, maxUserFlux;

// 递归删除节点及其子树
void deleteNode(Node *node) {
    if (!node)
        return;
    if (node->parent) {
        node->parent->removeChild(node);
    }
    while (!node->children.empty()) {
        deleteNode(node->children.back());
    }
    delete node;
}

// 重新计算所有活跃传输的完成时间，并更新事件队列
void recalcTransfers(int current_time,
                     vector<User *> &activeTransfers,
                     priority_queue<Event, vector<Event>, function<bool(const Event &, const Event &)>> &pq,
                     int &nextEventId) {
    int userTotal = activeTransfers.size();
    if (userTotal == 0)
        return;

    int presentMaxUserFlux = maxServerFlux / userTotal;

    for (User *user : activeTransfers) {
        int flux = min(presentMaxUserFlux, maxUserFlux);
        int completeTime;
        if (flux == 0) {
            // 无法传输，暂不生成完成事件
            user->currentCompleteEventId = -1;
            continue;
        }
        int remaining = user->remainingSize;
        if (remaining == 0) {
            completeTime = current_time;
        } else {
            completeTime = current_time + (remaining + flux - 1) / flux;
        }

        int evId = nextEventId++;
        user->currentCompleteEventId = evId;

        Event e;
        e.time = completeTime;
        e.type = TRANSFER_COMPLETE;
        e.transferUserName = user->name;
        e.eventId = evId;
        e.valid = true;
        pq.push(e);
    }
}

// 处理传输完成事件
void processTransferComplete(const Event &e,
                             map<string, User *> &onlineUsers,
                             vector<User *> &activeTransfers,
                             priority_queue<Event, vector<Event>, function<bool(const Event &, const Event &)>> &pq,
                             int &nextEventId,
                             int current_time) {
    auto it = onlineUsers.find(e.transferUserName);
    if (it == onlineUsers.end())
        return;
    User *user = it->second;
    if (user->currentCompleteEventId != e.eventId)
        return;
    if (user->state != User::UPLOADING && user->state != User::DOWNLOADING)
        return;

    // 完成传输
    if (user->state == User::UPLOADING) {
        // 上传完成，文件状态变为normal
        Node *target = user->transferTarget;
        if (target && !target->isFolder) {
            target->setFileUploading(false);
        }
        // 文件夹上传不会走到这里（size=0立即完成）
    }
    // 下载完成不需要修改服务器

    user->state = User::IDLE;
    user->transferTarget = nullptr;
    user->currentCompleteEventId = -1;

    // 从活跃传输列表中移除
    auto it2 = find(activeTransfers.begin(), activeTransfers.end(), user);
    if (it2 != activeTransfers.end())
        activeTransfers.erase(it2);

    // 重新计算其他传输
    recalcTransfers(current_time, activeTransfers, pq, nextEventId);
}

// 递归解析文件系统（从输入流读取，直到遇到单独一行的减号）
Node *parseFolder(istream &in) {
    Node *folder = new Node("", true);
    string line;
    while (getline(in, line)) {
        // 去除首尾空白
        size_t start = line.find_first_not_of(" \t\r\n");
        if (start == string::npos)
            continue;
        size_t end = line.find_last_not_of(" \t\r\n");
        line = line.substr(start, end - start + 1);
        if (line == "-") {
            break;
        }
        istringstream iss(line);
        string name;
        int sz;
        iss >> name >> sz;
        if (sz == 0) {
            // 文件夹
            Node *subFolder = parseFolder(in);
            subFolder->name = name;
            folder->addChild(subFolder);
        } else {
            // 文件
            Node *file = new Node(name, false, sz);
            folder->addChild(file);
        }
    }
    return folder;
}

inline void solve(int Task_Id) {
    // 读取服务器参数
    cin >> maxUserNumber >> maxServerFlux >> maxUserFlux;
    cin.ignore(); // 忽略换行符

    // 解析初始文件系统
    Node *root = parseFolder(cin);

    // 读取命令，存入命令事件列表
    vector<Event> commandEvents;
    int order = 0;
    string line;
    while (getline(cin, line)) {
        if (line == "down")
            break;
        // 简单trim
        size_t start = line.find_first_not_of(" \t\r\n");
        if (start == string::npos)
            continue;
        size_t end = line.find_last_not_of(" \t\r\n");
        line = line.substr(start, end - start + 1);

        istringstream iss(line);
        int t;
        string name, cmd;
        iss >> t >> name >> cmd;
        vector<string> args;
        string arg;
        while (iss >> arg)
            args.push_back(arg);

        Event e;
        e.time = t;
        e.type = COMMAND;
        e.user = name;
        e.cmd = cmd;
        e.args = args;
        e.order = order++;
        e.valid = true;
        commandEvents.push_back(e);
    }

    // 事件队列比较器
    function<bool(const Event &, const Event &)> cmp = [](const Event &a, const Event &b) -> bool {
        if (a.time != b.time)
            return a.time > b.time;
        if (a.type != b.type)
            return a.type > b.type;
        if (a.type == COMMAND)
            return a.order > b.order;
        return false;
    };
    priority_queue<Event, vector<Event>, function<bool(const Event &, const Event &)>> pq(cmp);
    for (const auto &e : commandEvents)
        pq.push(e);

    map<string, User *> onlineUsers;
    int onlineCount = 0;
    vector<User *> activeTransfers;
    int nextEventId = 0;
    int current_time = 0;

    // 事件主循环
    while (!pq.empty()) {
        Event e = pq.top();
        pq.pop();
        if (!e.valid)
            continue;
        current_time = e.time;

        if (e.type == COMMAND) {
            string name = e.user;
            string cmd = e.cmd;
            vector<string> args = e.args;

            auto it = onlineUsers.find(name);
            User *user = (it != onlineUsers.end()) ? it->second : nullptr;

            if (cmd == "connect") {
                int type = stoi(args[0]);
                if (user != nullptr || onlineCount >= maxUserNumber) {
                    cout << "unsuccess" << endl;
                } else {
                    User *newUser = new User(name, type, root);
                    onlineUsers[name] = newUser;
                    onlineCount++;
                    cout << "success" << endl;
                }
            } else if (cmd == "quit") {
                if (user == nullptr) {
                    cout << "unsuccess" << endl;
                } else {
                    // 如果用户正在传输，中断并清理
                    if (user->state != User::IDLE) {
                        auto it2 = find(activeTransfers.begin(), activeTransfers.end(), user);
                        if (it2 != activeTransfers.end())
                            activeTransfers.erase(it2);
                        if (user->state == User::UPLOADING) {
                            deleteNode(user->transferTarget);
                        }
                        user->state = User::IDLE;
                        user->transferTarget = nullptr;
                        user->currentCompleteEventId = -1;
                        recalcTransfers(current_time, activeTransfers, pq, nextEventId);
                    }
                    onlineUsers.erase(name);
                    delete user;
                    onlineCount--;
                    cout << "success" << endl;
                }
            } else {
                // 以下命令均要求用户已连接
                if (user == nullptr) {
                    cout << "unsuccess" << endl;
                    continue;
                }

                if (cmd == "cd") {
                    string folderName = args[0];
                    if (user->state != User::IDLE) {
                        cout << "unsuccess" << endl;
                    } else {
                        Node *target = user->position->findChild(folderName);
                        if (target && target->isFolder && !target->isUploading()) {
                            user->position = target;
                            cout << "success" << endl;
                        } else {
                            cout << "unsuccess" << endl;
                        }
                    }
                } else if (cmd == "cd..") {
                    if (user->state != User::IDLE) {
                        cout << "unsuccess" << endl;
                    } else if (user->position == root) {
                        cout << "unsuccess" << endl;
                    } else {
                        user->position = user->position->parent;
                        cout << "success" << endl;
                    }
                } else if (cmd == "download") {
                    string targetName = args[0];
                    if (user->state != User::IDLE || user->type != 2) {
                        cout << "unsuccess" << endl;
                    } else {
                        Node *target = user->position->findChild(targetName);
                        if (target && !target->isUploading()) {
                            int totalSize = target->getTotalSize();
                            user->state = User::DOWNLOADING;
                            user->transferTarget = target;
                            user->remainingSize = totalSize;
                            activeTransfers.push_back(user);
                            recalcTransfers(current_time, activeTransfers, pq, nextEventId);
                            cout << "success" << endl;
                        } else {
                            cout << "unsuccess" << endl;
                        }
                    }
                } else if (cmd == "upload") {
                    string targetName = args[0];
                    int size = stoi(args[1]);
                    if (user->state != User::IDLE || user->type != 1) {
                        cout << "unsuccess" << endl;
                    } else {
                        Node *existing = user->position->findChild(targetName);
                        if (existing) {
                            cout << "unsuccess" << endl;
                        } else {
                            if (size == 0) {
                                // 空文件夹，立即完成
                                Node *folder = new Node(targetName, true, 0);
                                user->position->addChild(folder);
                                cout << "success" << endl;
                            } else {
                                // 上传文件
                                Node *file = new Node(targetName, false, size);
                                file->uploading = true; // 直接设置，addChild会处理状态传播
                                user->position->addChild(file);
                                user->state = User::UPLOADING;
                                user->transferTarget = file;
                                user->remainingSize = size;
                                activeTransfers.push_back(user);
                                recalcTransfers(current_time, activeTransfers, pq, nextEventId);
                                cout << "success" << endl;
                            }
                        }
                    }
                } else {
                    cout << "unsuccess" << endl;
                }
            }
        } else { // TRANSFER_COMPLETE
            processTransferComplete(e, onlineUsers, activeTransfers, pq, nextEventId, current_time);
        }
    }

    // 清理内存
    deleteNode(root);
    for (auto &p : onlineUsers)
        delete p.second;

    return;
}
} // namespace TANGYIXIAO
