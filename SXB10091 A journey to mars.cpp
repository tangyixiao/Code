#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n;
long long p[N], d[N], pp[N], dd[N], S[2 * N];
int dq[2 * N];
bool f[N], g[N];

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> d[i];
    }
}

inline void run(long long *a, long long *b, bool *out) {
    S[0] = 0;
    for (int i = 1; i <= n; i++) {
        S[i] = S[i - 1] + a[i] - b[i];
    }
    for (int i = 1; i <= n; i++) {
        S[n + i] = S[n] + S[i];
    }
    int hd = 1, tl = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= i + n - 1; j++) {
            while (hd <= tl && S[dq[tl]] >= S[j]) {
                tl--;
            }
            dq[++tl] = j;
        }
        while (hd <= tl && dq[hd] < i) {
            hd++;
        }
        out[i] = S[dq[hd]] >= S[i - 1];
    }
    return;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        pp[i] = p[n - i + 1];
        dd[i] = i == n ? d[n] : d[n - i];
    }
    run(p, d, f);
    run(pp, dd, g);
    for (int i = 1; i <= n; i++) {
        cout << (f[i] || g[n - i + 1] ? "TAK" : "NIE") << "\n";
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
