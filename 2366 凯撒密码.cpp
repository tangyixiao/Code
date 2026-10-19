#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

char a[N], b[N];
int n;
bool dig;

inline void input() {
    cin >> a >> b;
    dig = true;
    for (int i = 0; a[i]; ++i) {
        if (a[i] < '0' || a[i] > '9') {
            dig = false;
            break;
        }
    }
    if (dig) {
        n = atoi(a), swap(a, b);
    } else {
        n = atoi(b);
    }
}

inline void solve() {
    for (int i = 0; a[i]; ++i) {
        a[i] = char('a' + (a[i] - 'a' + n) % 26);
    }
    cout << a << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
