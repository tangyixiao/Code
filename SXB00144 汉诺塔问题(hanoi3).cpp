#include <bits/stdc++.h>
using namespace std;

int n;

inline void hanoi(int k, char a, char b, char c) {
    if (k == 0) {
        return;
    }
    hanoi(k - 1, a, c, b);
    cout << a << "->" << k << "->" << c << "\n";
    hanoi(k - 1, b, a, c);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
