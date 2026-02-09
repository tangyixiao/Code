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
priority_queue<int> q;
int a[805], b[805], n, m, k, o, oo;
int main() {
    Init_IO();
    cin >> n >> m >> k;
    q.push(0);
    while (n--) {
        for (int i = 1; i <= m; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + m);
        o = oo = 0;
        while (!q.empty())
            b[++o] = q.top(), q.pop();
        for (int i = 1; i <= m; ++i) {
            for (int j = o; j >= 1; --j) {
                if (oo < k) {
                    q.push(a[i] + b[j]), ++oo;
                } else {
                    if (q.top() <= a[i] + b[j]) {
                        break;
                    } else {
                        q.pop(), q.push(a[i] + b[j]);
                    }
                }
            }
        }
    }
    o = 0;
    while (!q.empty()) {
        b[++o] = q.top(), q.pop();
    }
    for (int i = o; i >= 1; --i) {
        printf("%d ", b[i]);
    }
    return 0;
}
