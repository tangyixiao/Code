#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

char a[N], b[N];
bool mk[256];

inline void input() {
    cin.getline(a, sizeof(a));
    cin.getline(b, sizeof(b));
}

inline void solve() {
    int m = strlen(b);
    for (int i = 0; i < m; i++) {
        mk[(int)b[i]] = true;
    }
    int n = strlen(a);
    string r;
    for (int i = 0; i < n; i++) {
        if (!mk[(int)a[i]]) {
            r += a[i];
        }
    }
    cout << r << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}