#include <bits/stdc++.h>
using namespace std;

string s;
long long f[5];

inline void input() {}

inline void solve() {
    for (int i = 1; i <= 2023; ++i) {
        s += to_string(i);
    }
    f[0] = 1;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 4; j >= 1; --j) {
            if (s[i] == "2023"[j - 1]) {
                f[j] += f[j - 1];
            }
        }
    }
    cout << f[4] << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}