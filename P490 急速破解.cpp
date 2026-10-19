#include <bits/stdc++.h>
using namespace std;

const int N = 205;

inline int cp(string x, string y) {
    if (x.size() != y.size()) {
        return x.size() < y.size() ? -1 : 1;
    }
    if (x == y) {
        return 0;
    }
    return x < y ? -1 : 1;
}

inline void sb(string &x, string y) {
    int j = y.size() - 1, d = 0;
    string r;
    for (int i = x.size() - 1; i >= 0; i--) {
        int v = x[i] - '0' - d - (j >= 0 ? y[j--] - '0' : 0);
        if (v < 0) {
            v += 10, d = 1;
        } else {
            d = 0;
        }
        r += char('0' + v);
    }
    while (r.size() > 1 && r[r.size() - 1] == '0') {
        r.erase(r.size() - 1);
    }
    reverse(r.begin(), r.end());
    x = r;
    return;
}

inline void ml(string &x, string y) {
    int n = x.size(), m = y.size(), c[2 * N] = {0};
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            c[i + j + 1] += (x[i] - '0') * (y[j] - '0');
        }
    }
    for (int i = n + m - 1; i > 0; i--) {
        c[i - 1] += c[i] / 10, c[i] %= 10;
    }
    string r;
    for (int i = 0; i < n + m; i++) {
        r += char('0' + c[i]);
    }
    x = r;
    return;
}

inline void dv(string x, string y, string &q, string &r) {
    q.clear(), r = "0";
    for (int i = 0; i < (int)x.size(); i++) {
        r += x[i];
        while (r.size() > 1 && r[0] == '0') {
            r.erase(0, 1);
        }
        int k = 0;
        for (; cp(r, y) >= 0; k++) {
            sb(r, y);
        }
        q += char('0' + k);
    }
    while (q.size() > 1 && q[0] == '0') {
        q.erase(0, 1);
    }
    return;
}

inline void input() {}

inline void solve() {
    string a, b, x, y, q, r, t;
    cin >> a >> b;
    x = a, y = b;
    while (y != "0") {
        dv(x, y, q, r), t = r, x = y, y = t;
    }
    dv(a, x, q, r);
    ml(q, b);
    cout << q << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
