#include <bits/stdc++.h>
using namespace std;

char ch;
int a;
float x;
double y;

inline void input() { cin >> ch >> a >> x >> y; }

inline void solve() {
    cout << ch << " " << a << " " << setprecision(6) << fixed << (double)x << " " << y << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}