#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
char c1[N], c2[N];

inline void input() {}

inline void solve() {
    cin >> c1 >> c2;
    int l1 = strlen(c1), l2 = strlen(c2);
    for (int i = 0; i < l2; ++i) {
        char a = c2[i], b = c1[i % l1];
        if (b >= 'A' && b <= 'Z') {
            b -= 'A';
        } else {
            b -= 'a';
        }
        if (a >= 'A' && a <= 'Z') {
            cout << char('A' + (a - 'A' - b + 26) % 26);
        } else {
            cout << char('a' + (a - 'a' - b + 26) % 26);
        }
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}