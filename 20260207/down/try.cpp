#include <bits/stdc++.h>
#define Judge
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
inline void Judge_File(string File_Name) {
    freopen((File_Name + Insuffix).c_str(), "r", stdin);
    freopen((File_Name + Outsuffix).c_str(), "w", stdout);
    return;
}
inline void Local_File(string File_Name, int File_Idx) {
    freopen((File_Name + to_string(File_Idx) + Insuffix).c_str(), "r", stdin);
    freopen((File_Name + to_string(File_Idx) + Outsuffix).c_str(), "w", stdout);
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
inline void Print_Time_Count(string Programe_Name) {
    cerr << fixed << setprecision(4) << "\n" << Programe_Name << " Time: " << Time_Count() << "s\n";
    return;
}
} // namespace TIME
using namespace TIME;
const int N = 1e3 + 5, inf = 2e9;

signed main() {
    Init_IO();
    freopen("input.txt","w",stdout);
    for(int i=1;i<=50*50*50;i++){
        cout<<0<<" ";
    }
    return 0;
}