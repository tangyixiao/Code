#include <bits/stdc++.h>
using namespace std;

const int N = 305;
string s;
int a[N], n;

inline void input() {
    cin >> s;
    return;
}

inline void solve() {
    int m = s.size();
    for (int i = 0; i < m; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            int v = 0;
            while (i < m && s[i] >= '0' && s[i] <= '9') {
                v = v * 10 + s[i] - '0', i++;
            }
            i--, a[n++] = v;
        }
    }
    if (!n) {
        cout << 0 << "\n";
        return;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i + 1 == n ? "" : ",");
    }
    cout << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
