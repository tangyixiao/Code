
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
const int MAX_O = 5;
int O; // 全局操作上限

// 状态编码与解码
struct State {
    int E, S;         // 体力 1~20，0表示死亡
    int handE, handS; // 手牌数 0~3
    // 小E场上牌：cnt1u, cnt1a, cnt2u, cnt2a (体力1未攻，体力1已攻，体力2未攻，体力2已攻)
    int e1u, e1a, e2u, e2a;
    // 老师场上牌
    int t1u, t1a, t2u, t2a;
    int turn;      // 0=E, 1=老师
    int used_op;   // 本回合已用技能+打牌次数 0..O
    int has_acted; // 本回合是否已行动 0/1

    // 编码为64位整数
    uint64_t encode() const {
        uint64_t val = 0;
        val |= (uint64_t)E;
        val |= (uint64_t)S << 5;
        val |= (uint64_t)handE << 10;
        val |= (uint64_t)handS << 12;
        val |= (uint64_t)e1u << 14;
        val |= (uint64_t)e1a << 17;
        val |= (uint64_t)e2u << 20;
        val |= (uint64_t)e2a << 23;
        val |= (uint64_t)t1u << 26;
        val |= (uint64_t)t1a << 29;
        val |= (uint64_t)t2u << 32;
        val |= (uint64_t)t2a << 35;
        val |= (uint64_t)turn << 38;
        val |= (uint64_t)used_op << 39;
        val |= (uint64_t)has_acted << 42;
        return val;
    }

    static State decode(uint64_t val) {
        State s;
        s.E = val & 0x1F;
        s.S = (val >> 5) & 0x1F;
        s.handE = (val >> 10) & 0x3;
        s.handS = (val >> 12) & 0x3;
        s.e1u = (val >> 14) & 0x7;
        s.e1a = (val >> 17) & 0x7;
        s.e2u = (val >> 20) & 0x7;
        s.e2a = (val >> 23) & 0x7;
        s.t1u = (val >> 26) & 0x7;
        s.t1a = (val >> 29) & 0x7;
        s.t2u = (val >> 32) & 0x7;
        s.t2a = (val >> 35) & 0x7;
        s.turn = (val >> 38) & 0x1;
        s.used_op = (val >> 39) & 0x7;
        s.has_acted = (val >> 42) & 0x1;
        return s;
    }

    bool operator==(const State &o) const {
        return encode() == o.encode();
    }
};

struct StateHash {
    size_t operator()(uint64_t x) const {
        return hash<uint64_t>()(x);
    }
};

// 全局缓存，键为encode值
unordered_map<uint64_t, double, StateHash> memo;

// 获取当前玩家的手牌数
int &get_hand(State &s, int player) {
    return player == 0 ? s.handE : s.handS;
}

// 获取当前玩家的场上牌计数（引用不方便，用指针）
void get_field_counts(State &s, int player, int *cnt1u, int *cnt1a, int *cnt2u, int *cnt2a) {
    if (player == 0) {
        *cnt1u = s.e1u;
        *cnt1a = s.e1a;
        *cnt2u = s.e2u;
        *cnt2a = s.e2a;
    } else {
        *cnt1u = s.t1u;
        *cnt1a = s.t1a;
        *cnt2u = s.t2u;
        *cnt2a = s.t2a;
    }
}

// 设置当前玩家的场上牌计数
void set_field_counts(State &s, int player, int cnt1u, int cnt1a, int cnt2u, int cnt2a) {
    if (player == 0) {
        s.e1u = cnt1u;
        s.e1a = cnt1a;
        s.e2u = cnt2u;
        s.e2a = cnt2a;
    } else {
        s.t1u = cnt1u;
        s.t1a = cnt1a;
        s.t2u = cnt2u;
        s.t2a = cnt2a;
    }
}

// 场上牌总数
int total_minions(const State &s, int player) {
    if (player == 0)
        return s.e1u + s.e1a + s.e2u + s.e2a;
    else
        return s.t1u + s.t1a + s.t2u + s.t2a;
}

// 抽牌
void draw_card(State &s, int player) {
    int &hand = get_hand(s, player);
    if (hand < 3)
        hand++;
}

// 重置攻击标记（回合结束时调用）
void reset_attack_marks(State &s) {
    s.e1u += s.e1a;
    s.e1a = 0;
    s.e2u += s.e2a;
    s.e2a = 0;
    s.t1u += s.t1a;
    s.t1a = 0;
    s.t2u += s.t2a;
    s.t2a = 0;
}

// 检查游戏是否结束，返回 2表示未结束，0表示小E输，1表示小E赢
int game_over(const State &s) {
    if (s.E <= 0)
        return 0;
    if (s.S <= 0)
        return 1;
    return 2;
}

// ---------- 打牌随机伤害模拟 ----------
struct TempRole {
    int type;      // 0:E玩家, 1:S玩家, 2:E牌, 3:S牌
    int idx;       // 对于牌，在列表中的索引
    int hp;        // 当前体力
    bool attacked; // 仅对牌有效
};

// 将状态展开为角色列表
vector<TempRole> expand_roles(const State &s) {
    vector<TempRole> roles;
    if (s.E > 0)
        roles.push_back({0, -1, s.E, false});
    if (s.S > 0)
        roles.push_back({1, -1, s.S, false});
    // 小E的牌
    auto add_minions = [&](int cnt1u, int cnt1a, int cnt2u, int cnt2a, int owner) {
        for (int i = 0; i < cnt1u; i++)
            roles.push_back({owner, -1, 1, false});
        for (int i = 0; i < cnt1a; i++)
            roles.push_back({owner, -1, 1, true});
        for (int i = 0; i < cnt2u; i++)
            roles.push_back({owner, -1, 2, false});
        for (int i = 0; i < cnt2a; i++)
            roles.push_back({owner, -1, 2, true});
    };
    add_minions(s.e1u, s.e1a, s.e2u, s.e2a, 2);
    add_minions(s.t1u, s.t1a, s.t2u, s.t2a, 3);
    // 为牌分配索引以便更新
    for (size_t i = 0; i < roles.size(); i++) {
        if (roles[i].type >= 2)
            roles[i].idx = i;
    }
    return roles;
}

// 将角色列表压缩回State（只压缩牌，玩家体力直接设置）
State compress_roles(const vector<TempRole> &roles, const State &base) {
    State s = base;
    s.E = 0;
    s.S = 0;
    s.e1u = s.e1a = s.e2u = s.e2a = 0;
    s.t1u = s.t1a = s.t2u = s.t2a = 0;
    for (const auto &r : roles) {
        if (r.type == 0)
            s.E = r.hp;
        else if (r.type == 1)
            s.S = r.hp;
        else if (r.type == 2) {
            if (r.hp == 1)
                r.attacked ? s.e1a++ : s.e1u++;
            else if (r.hp == 2)
                r.attacked ? s.e2a++ : s.e2u++;
        } else if (r.type == 3) {
            if (r.hp == 1)
                r.attacked ? s.t1a++ : s.t1u++;
            else if (r.hp == 2)
                r.attacked ? s.t2a++ : s.t2u++;
        }
    }
    return s;
}

// 打牌随机伤害结果
map<uint64_t, double> play_card_damage(const State &s) {
    map<uint64_t, double> res;
    vector<TempRole> init_roles = expand_roles(s);

    function<void(int, double, vector<TempRole> &)> dfs = [&](int depth, double prob, vector<TempRole> &roles) {
        // 检查游戏是否结束
        int e_hp = 0, s_hp = 0;
        for (auto &r : roles) {
            if (r.type == 0)
                e_hp = r.hp;
            else if (r.type == 1)
                s_hp = r.hp;
        }
        if (e_hp <= 0 || s_hp <= 0) {
            State end_s = compress_roles(roles, s);
            end_s.E = e_hp;
            end_s.S = s_hp;
            res[end_s.encode()] += prob;
            return;
        }
        if (depth == 3) {
            State ns = compress_roles(roles, s);
            ns.E = e_hp;
            ns.S = s_hp;
            res[ns.encode()] += prob;
            return;
        }

        // 收集存活角色索引
        vector<int> alive_idx;
        for (size_t i = 0; i < roles.size(); i++) {
            if (roles[i].hp > 0)
                alive_idx.push_back(i);
        }
        if (alive_idx.empty()) {
            // 没有存活角色？不可能
            State ns = compress_roles(roles, s);
            ns.E = e_hp;
            ns.S = s_hp;
            res[ns.encode()] += prob;
            return;
        }
        double p = 1.0 / alive_idx.size();
        for (int idx : alive_idx) {
            vector<TempRole> new_roles = roles;
            new_roles[idx].hp--;
            // 如果牌死亡，hp=0，后续不再参与
            dfs(depth + 1, prob * p, new_roles);
        }
    };

    vector<TempRole> start_roles = init_roles;
    dfs(0, 1.0, start_roles);
    return res;
}

// 主DFS
double dfs(State s) {
    // 回合开始抽牌（在回合内决策前）
    // 注意：状态中的turn表示当前回合的玩家，此时还未抽牌
    // 所以我们先抽牌
    draw_card(s, s.turn);

    uint64_t code = s.encode();
    if (memo.count(code))
        return memo[code];

    int over = game_over(s);
    if (over != 2)
        return over == 1 ? 1.0 : 0.0;

    double best = (s.turn == 0) ? -1.0 : 2.0; // max for E, min for S

    int player = s.turn;
    int &my_hp = (player == 0) ? s.E : s.S;
    int &op_hp = (player == 0) ? s.S : s.E;
    int my_hand = get_hand(s, player);
    int cnt1u, cnt1a, cnt2u, cnt2a;
    get_field_counts(s, player, &cnt1u, &cnt1a, &cnt2u, &cnt2a);
    int my_total_minions = cnt1u + cnt1a + cnt2u + cnt2a;
    int op_cnt1u, op_cnt1a, op_cnt2u, op_cnt2a;
    get_field_counts(s, 1 - player, &op_cnt1u, &op_cnt1a, &op_cnt2u, &op_cnt2a);

    // 1. 技能
    if (s.used_op < O && my_hp > 2) {
        State ns = s;
        ns.has_acted = 1;
        ns.used_op++;
        if (player == 0)
            ns.E -= 2;
        else
            ns.S -= 2;
        draw_card(ns, player); // 抽牌
        double val = dfs(ns);
        if (player == 0)
            best = max(best, val);
        else
            best = min(best, val);
    }

    // 2. 攻击
    // 攻击玩家
    if (cnt1u + cnt2u > 0) {
        // 用一张未攻击的牌打脸
        // 枚举用体力1还是体力2
        for (int use2 = 0; use2 <= 1; use2++) {
            if (use2 && cnt2u == 0)
                continue;
            if (!use2 && cnt1u == 0)
                continue;
            State ns = s;
            ns.has_acted = 1;
            if (use2) {
                if (player == 0)
                    ns.e2u--, ns.e2a++;
                else
                    ns.t2u--, ns.t2a++;
            } else {
                if (player == 0)
                    ns.e1u--, ns.e1a++;
                else
                    ns.t1u--, ns.t1a++;
            }
            // 对方-3
            if (player == 0)
                ns.S -= 3;
            else
                ns.E -= 3;
            double val = dfs(ns);
            if (player == 0)
                best = max(best, val);
            else
                best = min(best, val);
        }
    }
    // 攻击对方牌（同归于尽）
    if (cnt1u + cnt2u > 0) {
        // 枚举自己的攻击牌类型
        for (int use2_self = 0; use2_self <= 1; use2_self++) {
            if (use2_self && cnt2u == 0)
                continue;
            if (!use2_self && cnt1u == 0)
                continue;
            // 枚举对方被摧毁的牌类型
            int total_op_minions = op_cnt1u + op_cnt1a + op_cnt2u + op_cnt2a;
            if (total_op_minions == 0)
                continue;
            // 对方四种类型
            for (int op_type = 0; op_type < 4; op_type++) {
                int *op_cnt = nullptr;
                if (op_type == 0)
                    op_cnt = (player == 0) ? &s.t1u : &s.e1u;
                else if (op_type == 1)
                    op_cnt = (player == 0) ? &s.t1a : &s.e1a;
                else if (op_type == 2)
                    op_cnt = (player == 0) ? &s.t2u : &s.e2u;
                else
                    op_cnt = (player == 0) ? &s.t2a : &s.e2a;
                if (*op_cnt == 0)
                    continue;

                State ns = s;
                ns.has_acted = 1;
                // 自己牌摧毁（从unused中移除，不进入used直接消失）
                if (use2_self) {
                    if (player == 0)
                        ns.e2u--;
                    else
                        ns.t2u--;
                } else {
                    if (player == 0)
                        ns.e1u--;
                    else
                        ns.t1u--;
                }
                // 对方牌摧毁
                if (player == 0) {
                    if (op_type == 0)
                        ns.t1u--;
                    else if (op_type == 1)
                        ns.t1a--;
                    else if (op_type == 2)
                        ns.t2u--;
                    else
                        ns.t2a--;
                } else {
                    if (op_type == 0)
                        ns.e1u--;
                    else if (op_type == 1)
                        ns.e1a--;
                    else if (op_type == 2)
                        ns.e2u--;
                    else
                        ns.e2a--;
                }
                double val = dfs(ns);
                if (player == 0)
                    best = max(best, val);
                else
                    best = min(best, val);
            }
        }
    }

    // 3. 打牌
    if (s.used_op < O && my_hand > 0 && my_total_minions < 4) {
        // 先进行随机伤害模拟
        auto outcomes = play_card_damage(s);
        for (auto &[code_out, prob] : outcomes) {
            State ns = State::decode(code_out);
            int over2 = game_over(ns);
            double val;
            if (over2 == 1)
                val = 1.0;
            else if (over2 == 0)
                val = 0.0;
            else {
                // 未结束，添加牌
                ns.used_op++;
                ns.has_acted = 1;
                get_hand(ns, player)--; // 消耗一张手牌
                // 添加一张体力2已攻击牌
                if (player == 0)
                    ns.e2a++;
                else
                    ns.t2a++;
                val = dfs(ns);
            }
            if (player == 0)
                best = max(best, val);
            else
                best = min(best, val);
        }
    }

    // 4. 结束回合
    if (s.has_acted) {
        State ns = s;
        ns.turn = 1 - ns.turn;
        ns.used_op = 0;
        ns.has_acted = 0;
        reset_attack_marks(ns);
        double val = dfs(ns);
        if (player == 0)
            best = max(best, val);
        else
            best = min(best, val);
    }

    memo[code] = best;
    return best;
}
inline void solve(int Task_Id) {

    int T;
    cin >> T >> O;
    while (T--) {
        int E, S;
        cin >> E >> S;
        State init;
        init.E = E;
        init.S = S;
        init.e1u = init.e1a = init.e2u = init.e2a = 0;
        init.t1u = init.t1a = init.t2u = init.t2a = 0;
        int c;
        cin >> c;
        for (int i = 0; i < c; i++) {
            int w;
            cin >> w;
            if (w == 1)
                init.t1u++;
            else
                init.t2u++;
        }
        int p;
        cin >> p;
        for (int i = 0; i < p; i++) {
            int w;
            cin >> w;
            if (w == 1)
                init.e1u++;
            else
                init.e2u++;
        }
        cin >> init.handS >> init.handE; // 注意输入顺序：老师手牌 小E手牌
        init.turn = 0;                   // 小E回合
        init.used_op = 0;
        init.has_acted = 0;
        double ans = dfs(init);
        cout << ans << '\n';
    }
    return;
}
} // namespace TANGYIXIAO
