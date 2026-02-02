#include <bits/stdc++.h>
using namespace std;
namespace IO {
inline void Init_IO() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return;
}
} // namespace IO
using namespace IO;
namespace FILE_IO {
const string Insuffix = ".in";
const string Outsuffix = ".out";
const string Anssuffix = ".ans";
inline void Judge_File(string Name) {
    freopen((Name + Insuffix).c_str(), "r", stdin);
    freopen((Name + Outsuffix).c_str(), "w", stdout);
    return;
}
inline void Local_File(string Name, int Idx) {
    freopen((Name + to_string(Idx) + Insuffix).c_str(), "r", stdin);
    freopen((Name + to_string(Idx) + Outsuffix).c_str(), "w", stdout);
    return;
}
} // namespace FILE_IO
using namespace FILE_IO;
namespace TIME {
clock_t Start_Time, End_Time;
inline void Start_Time_Count() {
    Start_Time = clock();
    return;
}
inline void End_Time_Count() {
    End_Time = clock();
    return;
}
inline double Time_Count() {
    double Time = (double)(End_Time - Start_Time) / CLOCKS_PER_SEC;
    return Time;
}
inline void Print_Time_Count() {
    cerr << fixed << setprecision(4) << "Time: " << Time_Count() << "s\n";
    return;
}
} // namespace TIME
using namespace TIME;
signed main() {
    Init_IO();
    Start_Time_Count();
    volatile int cnt = 0; // 使用 volatile
    for (int i = 0; i < 1e9; i++) {
        cnt++;
    }

    End_Time_Count();
    Print_Time_Count();
    return 0;
}