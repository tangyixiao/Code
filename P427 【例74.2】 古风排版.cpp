#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

char s[N], a[N][N];
int n, w;

inline void input() {
    cin >> n;
    cin.ignore();
    cin.getline(s, sizeof(s));
    int m = strlen(s);
    while (m && (s[m - 1] == '\r' || s[m - 1] == ' ')) {
        s[--m] = '\0';
    }
    w = (m + n - 1) / n;
}

inline void solve() {
    int m = strlen(s);
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = w - 1; j >= 0; j--) {
            int p = j * n + i;
            a[i][k++] = (p < m ? s[p] : ' ');
        }
        a[i][k] = '\0';
        cout << a[i] << "\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}