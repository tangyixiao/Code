#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
bool p[N];
int n;

inline void input() {
    cin >> n;
}

inline bool chk(int x) {
    return !p[x];
}

inline void solve() {
    for (int i = 2; i * i <= n; ++i) {
        if (p[i]) {
            continue;
        }
        for (int j = i * i; j <= n; j += i) {
            p[j] = true;
        }
    }
    for (int i = 4; i <= n; i += 2) {
        int a = 0;
        for (int j = 2; j <= i / 2; ++j) {
            if (chk(j) && chk(i - j)) {
                a = j;
                break;
            }
        }
        if (a == 0) {
            cout << "验证失败！\n";
            continue;
        }
        cout << i << "=" << a << "+" << i - a << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
