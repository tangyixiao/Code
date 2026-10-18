#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
char op;

inline void input() {}

inline void solve() {
    cin >> a >> op >> b;
    if (op == '+') {
        cout << a + b << "\n";
    } else if (op == '-') {
        cout << a - b << "\n";
    } else if (op == '*') {
        cout << a * b << "\n";
    } else if (op == '/') {
        cout << a / b << "\n";
    } else {
        cout << a % b << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}