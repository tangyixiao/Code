
/*
Copyright (C) 2026 TangYixiao
*/

#define JUDGE 0    
#define FILE_IDX 1 



#define FILE_NAME ""




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

namespace TANGYIXIAO {
namespace IO {
inline void Init_IO() { cin.tie(0)->sync_with_stdio(false); }
namespace FILE_IO {
const string Insuffix = ".in", Outsuffix = ".out", Anssuffix = ".ans";
inline void Judge_File(string File_Name) { freopen((File_Name + Insuffix).c_str(), "r", stdin), freopen((File_Name + Outsuffix).c_str(), "w", stdout); }
inline void Local_File(string File_Name, int File_Idx) { freopen((File_Name + to_string(File_Idx) + Insuffix).c_str(), "r", stdin), freopen((File_Name + to_string(File_Idx) + Outsuffix).c_str(), "w", stdout); }
} 
using namespace FILE_IO;
namespace INT128_IO {

istream&operator>>(istream&is,__int128&x){string s;is>>s;bool neg=false;x=0;for(char c:s){if(c=='-')neg=true;else x=x*10+(c-'0');}if(neg)x=-x;return is;}
ostream&operator<<(ostream&os,__int128 x){if(x==0)os<<0;else{string s,t;if(x<0)x=-x,t="-";while(x)s.push_back('0'+x%10),x/=10;reverse(s.begin(),s.end());os<<t<<s;}return os;}

} 
using namespace INT128_IO;
} 
using namespace IO;
namespace TIME {
clock_t Start_Time, End_Time;
inline void Start_Time_Count() { Start_Time = clock(); }
inline void End_Time_Count() { End_Time = clock(); }
inline double Time_Count() { return (double)(End_Time - Start_Time) / CLOCKS_PER_SEC; }
inline void Print_Time_Count(string Programe_Name) { cerr << fixed << setprecision(4) << "\n" + Programe_Name + " Time: " << Time_Count() << "s\n"; }
} 
using namespace TIME;
namespace DEBUGS {
inline void Debug_Print(string Debug_Message) { cerr << "\n" + Debug_Message + "\n"; }
} 
using namespace DEBUGS;
namespace BITS {
template <class T>
inline T lowbit(T x) { return x & (-x); }
template <class T>
inline T highbit(T x) { return (T)(log2(x) + 1); }
template <class T>
inline T Pop_Count(T x) { return __builtin_popcount(x); }
} 
using namespace BITS;
inline void solve(int Task_Id);
} 
using namespace TANGYIXIAO;
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
namespace TANGYIXIAO {
inline void solve(int Task_Id) {
    
    return;
}
} 
