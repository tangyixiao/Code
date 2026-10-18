#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

struct stu {
    char nm[25];
    int y, m, d;
    int i;
} a[N];

int n;

inline void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].nm >> a[i].y >> a[i].m >> a[i].d, a[i].i = i;
    }
}

inline void solve() {
    sort(a, a + n, [](stu &x, stu &y) {
        if (x.y != y.y) {
            return x.y < y.y;
        }
        if (x.m != y.m) {
            return x.m < y.m;
        }
        if (x.d != y.d) {
            return x.d < y.d;
        }
        return x.i > y.i;
    });
    for (int i = 0; i < n; i++) {
        cout << a[i].nm << "\n";
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