#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
const int M = 3e2 + 5;

int n;
char s[N][M];

inline bool ck(char *a, char *b) {
    int x = strlen(a), y = strlen(b);
    if (x != y) {
        return x < y;
    }
    int p = strcmp(a, b);
    if (p) {
        return p < 0;
    }
    int ca = 0, cb = 0;
    for (int i = 0; i < x; ++i) {
        ca += a[i] == '1', cb += b[i] == '1';
    }
    return ca < cb;
}

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        int j = i;
        while (j > 1 && ck(s[j], s[j - 1])) {
            swap(s[j], s[j - 1]);
            --j;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << s[i] << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
