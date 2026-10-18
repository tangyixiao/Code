#include <bits/stdc++.h>
using namespace std;

const int N = 6e4 + 5;
int n, a[10], tot;
string r[N];

inline void input() {
    cin >> n;
}

inline void solve() {
    for (int i = 0; i < 10; ++i) {
        a[i] = 1;
    }
    while (true) {
        int sum = 0;
        for (int i = 0; i < 10; ++i) {
            sum += a[i];
        }
        if (sum == n) {
            ++tot;
            for (int i = 0; i < 10; ++i) {
                if (i) {
                    r[tot] += ' ';
                }
                r[tot] += char('0' + a[i]);
            }
        }
        int i = 9;
        while (i >= 0 && a[i] == 3) {
            a[i] = 1;
            --i;
        }
        if (i < 0) {
            break;
        }
        ++a[i];
    }
    cout << tot << "\n";
    for (int i = 1; i <= tot; ++i) {
        cout << r[i] << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}