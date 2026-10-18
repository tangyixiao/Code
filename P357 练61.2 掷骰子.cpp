#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int s[3], c[N];

inline void input() { cin >> s[0] >> s[1] >> s[2]; }

inline void solve() {
    for (int i = 1; i <= s[0]; i++) {
        for (int j = 1; j <= s[1]; j++) {
            for (int k = 1; k <= s[2]; k++) {
                c[i + j + k]++;
            }
        }
    }
    int r = 3, mx = 0;
    for (int i = 3; i <= s[0] + s[1] + s[2]; i++) {
        if (c[i] > mx) {
            mx = c[i], r = i;
        }
    }
    cout << r << "\n";
    return;
}

signed main() {
    input(), solve();
    return 0;
}