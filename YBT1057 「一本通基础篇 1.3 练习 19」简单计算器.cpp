#include <bits/stdc++.h>
using namespace std;

int a, b;
char op;

inline void input() {
    cin >> a >> b >> op;
}

inline void solve() {
    if (op == '+') {
        cout << a + b << "\n";
    } else if (op == '-') {
        cout << a - b << "\n";
    } else if (op == '*') {
        cout << a * b << "\n";
    } else if (op == '/') {
        if (!b) {
            cout << "Divided by zero!\n";
        } else {
            cout << a / b << "\n";
        }
    } else {
        cout << "Invalid operator!\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
