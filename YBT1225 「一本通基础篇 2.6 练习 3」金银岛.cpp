#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int k, w, s, a[N];
double v[N], d[N];

inline void input() {
    cin >> k;
    return;
}

inline void solve() {
    while (k--) {
        cin >> w >> s;
        for (int i = 0; i < s; ++i) {
            cin >> a[i] >> v[i], d[i] = v[i] / a[i];
        }
        for (int i = 0; i < s; ++i) {
            for (int j = i + 1; j < s; ++j) {
                if (d[j] > d[i]) {
                    swap(d[i], d[j]), swap(a[i], a[j]);
                }
            }
        }
        double c = w, ans = 0;
        for (int i = 0; i < s && c > 0; ++i) {
            double t = c < a[i] ? c : a[i];
            ans += t * d[i], c -= t;
        }
        printf("%.2f\n", ans);
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
