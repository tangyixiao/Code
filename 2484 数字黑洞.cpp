#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n;

inline void input() {
    cin >> n;
}

inline void solve() {
    input();
    int c = 0;
    for (; n != 495; c++) {
        int a = n / 100, b = n / 10 % 10, d = n % 10, t;
        if (a > b) {
            t = a, a = b, b = t;
        }
        if (b > d) {
            t = b, b = d, d = t;
        }
        if (a > b) {
            t = a, a = b, b = t;
        }
        n = d * 100 + b * 10 + a - a * 100 - b * 10 - d;
    }
    cout << c << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}