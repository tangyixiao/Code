#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n;
long long p[N], q[N];

inline long long g(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b, b = t;
    }
    return a;
}

inline void input() {
    cin >> n;
    p[0] = 0, q[0] = 1;
    for (int i = 1; i <= n; ++i) {
        long long a, b;
        char c;
        cin >> a >> c >> b;
        long long t = q[i - 1] / g(q[i - 1], b);
        p[i] = p[i - 1] * b + a * q[i - 1], q[i] = t * b;
        long long d = g(p[i], q[i]);
        p[i] /= d, q[i] /= d;
    }
}

inline void solve() {
    if (q[n] == 1) {
        cout << p[n] << "\n";
    } else {
        cout << p[n] << "/" << q[n] << "\n";
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
