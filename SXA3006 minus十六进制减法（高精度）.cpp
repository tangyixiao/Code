#include <bits/stdc++.h>
using namespace std;

int a[205], b[205], c[205];

int val(char ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    }
    return ch - 'A' + 10;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string x, y;
    cin >> x >> y;
    int n = x.size(), m = y.size();
    for (int i = 0; i < n; i++) {
        a[i] = val(x[n - 1 - i]);
    }
    for (int i = 0; i < m; i++) {
        b[i] = val(y[m - 1 - i]);
    }
    int len = max(n, m);
    for (int i = 0; i < len; i++) {
        c[i] += a[i] - b[i];
        if (c[i] < 0) {
            c[i] += 16;
            c[i + 1]--;
        }
    }
    int p = len;
    for (; p > 0 && c[p] == 0;) {
        p--;
    }
    for (int i = p; i >= 0; i--) {
        cout << (char)(c[i] < 10 ? '0' + c[i] : 'A' + c[i] - 10);
    }
    cout << "\n";
    return 0;
}
