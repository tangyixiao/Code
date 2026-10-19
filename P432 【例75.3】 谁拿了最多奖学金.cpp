#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

struct stu {
    char nm[25];
    int a, b, c;
    char g, w;
    int p;
} a[N];

int n;

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].nm >> a[i].a >> a[i].b >> a[i].g >> a[i].w >> a[i].p;
    }
}

inline void solve() {
    int mx = -1, sum = 0, k = 0;
    for (int i = 0; i < n; i++) {
        int v = 0;
        if (a[i].a > 80 && a[i].p >= 1) {
            v += 8000;
        }
        if (a[i].a > 85 && a[i].b > 80) {
            v += 4000;
        }
        if (a[i].a > 90) {
            v += 2000;
        }
        if (a[i].a > 85 && a[i].w == 'Y') {
            v += 1000;
        }
        if (a[i].b > 80 && a[i].g == 'Y') {
            v += 850;
        }
        sum += v;
        if (v > mx) {
            mx = v, k = i;
        }
    }
    cout << a[k].nm << "\n"
         << mx << "\n"
         << sum << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}